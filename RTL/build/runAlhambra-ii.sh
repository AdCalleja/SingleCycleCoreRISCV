#!/bin/bash
rm *.asc *.bin *.json

#Listen to Verilator Warnings
verilator -Wall -cc ./../src/SingleCycleCore.v --prefix SSC -I./../src/
#Synthesize
yosys -p "synth_ice40 -json hardware.json" -q ./../src/SingleCycleCore.v
#Place and Route
nextpnr-ice40 --hx4k --package tq144 --opt-timing --json hardware.json --asc hardware.asc --pcf ./../constrains/alhambra-ii_icestudio.pcf
#Program
icepack hardware.asc hardware.bin
iceprog hardware.bin
