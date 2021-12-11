#!/bin/bash
if [ ! -d ./output ]; then
  mkdir -p ./output;
else
  rm -rf ./output/*
fi

while getopts 'I:D:' flag; do
    case "${flag}" in
    	I) route=${OPTARG}
    	echo "Route is ${OPTARG}"
      	;;
        D) defines=${OPTARG}
        echo "Defines  = -D${defines}=1"
        ;;
    esac
done

#Listen to Verilator Warnings
#verilator -Wall -cc ./../src/SingleCycleCore.v --prefix SSC -I./../src/
#Synthesize
yosys -p "read_verilog -I${route} -D${defines}=1 ${route}SingleCycleCore.v; synth_ice40 -json ./output/hardware.json" -q #./../src/SingleCycleCore.v
#Place and Route
nextpnr-ice40 --hx4k --package tq144 --opt-timing --json ./output/hardware.json --asc ./output/hardware.asc --pcf ${route}../constrains/alhambra-ii_icestudio.pcf
#Program
icepack ./output/hardware.asc ./output/hardware.bin
iceprog ./output/hardware.bin
