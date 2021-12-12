#!/bin/bash
#Get path
SCRIPTPATH="$( cd -- "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )"
#Clean
rm $SCRIPTPATH/*.vvp $SCRIPTPATH/*.vcd 

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
yosys -p "read_verilog -I$SCRIPTPATH/../src/ -D${defines}=1 $SCRIPTPATH/../src/SingleCycleCore.v; synth_ice40 -json $SCRIPTPATH/hardware.json" -q #./../src/SingleCycleCore.v
#Place and Route
nextpnr-ice40 --hx4k --package tq144 --opt-timing --json $SCRIPTPATH/hardware.json --asc $SCRIPTPATH/hardware.asc --pcf $SCRIPTPATH/../constrains/alhambra-ii_icestudio.pcf
#Program
icepack $SCRIPTPATH/hardware.asc $SCRIPTPATH/hardware.bin
iceprog $SCRIPTPATH/hardware.bin
