#!/bin/bash

yosys -p "synth_ice40 -json ./build/hardware.json" -q SingleCycleCore.v
nextpnr-ice40 --hx4k --package tq144 --opt-timing --json ./build/hardware.json --asc ./build/hardware.asc --pcf alhambra-ii_icestudio.pcf
icepack ./build/hardware.asc ./build/hardware.bin
iceprog ./build/hardware.bin
