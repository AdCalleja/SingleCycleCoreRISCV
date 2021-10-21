#!/bin/bash
rm *.asc *.bin *.json

while getopts 'D:' flag; do
    case "${flag}" in
        D) defines=${OPTARG};;
        a) age=${OPTARG};;
        f) fullname=${OPTARG};;
    esac
done
echo 'Defines  = -D${defines}=1'
#Listen to Verilator Warnings
verilator -Wall -cc ./../src/SingleCycleCore.v --prefix SSC -I./../src/
#Synthesize
yosys -p "read_verilog -I./../src/ -D${defines}=1 ./../src/SingleCycleCore.v; synth_ice40 -json hardware.json" -q #./../src/SingleCycleCore.v
#Place and Route
nextpnr-ice40 --hx4k --package tq144 --opt-timing --json hardware.json --asc hardware.asc --pcf ./../constrains/alhambra-ii_icestudio.pcf
#Program
icepack hardware.asc hardware.bin
iceprog hardware.bin
