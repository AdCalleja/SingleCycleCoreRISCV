# SingleCycleCoreRISCV

This project is intended to be a simple implementation of some of the instructions of RISC-V base ISA RV32I. The core has been designed in [Logisim](http://www.cburch.com/logisim/) as a base to understand how the processor works and then implemented in HDL.

![Alt Text](images/SSC.gif)

## Design

This basic desing has been widely based in the work of [zeeshanrafique23](https://github.com/zeeshanrafique23), [RISC-V-single-cycle-core-Logisim](https://github.com/zeeshanrafique23/RISC-V-single-cycle-core-Logisim) and Chapter 4.4 of *Computer Organization and Design RISC-V Edition* as well as Appendix A.5 and Appendix C.2.

To simplify and clarify how it works, it's based in a Harvard architecture, Instruction memory (or *text*) storage and signal pathways are separate from Data memory.

The control, is divided in 2 levels, Main control and ALU control depending the later on the former. Both are designed entirely as combinational circuits, using a programmable logic array (PLA) configuration. 

The ALU is implemented using using single bit ALU blocks instead of Logisim operation blocks, 

The instructions implemented at the moment are: *lw*, *sw*, *beq*, *add*, *sub*, *and*, *or*.

 ## Logisim

### Diagrams

Top Level

![Top Level Diagram](images/topleveldiagram.jpg?raw=true "Top Level Diagram")

ALU

![ALU  Diagram](images/alu.jpg?raw=true "ALU Diagram")

1 bit ALU

![1 bit ALU Diagram](images/1bitalu.jpg?raw=true "1 bit ALU Diagram")

Main Control

![Main Control Diagram](images/maincontrol.jpg?raw=true "Main Control Diagram")

ALU Control

| Instruction Format | Instruction | Desired ALU action | ALUOp1 | ALUOp0 | I\[30\] | I\[14\] | I\[13\] | I\[12\] | AluCtrl |
| ------------------ | ----------- | ------------------ | ------ | ------ | ------- | ------- | ------- | ------- | ------- |
| I                  | lw          | add                | 0      | 0      | x       | x       | x       | x       | 0010    |
| S                  | sw          | add                | 0      | 0      | x       | x       | x       | x       | 0010    |
| B                  | beq         | substract          | 0      | 1      | x       | x       | x       | x       | 0110    |
| R                  | add         | add                | 1      | 0      | 0       | 0       | 0       | 0       | 0010    |
| R                  | sub         | substract          | 1      | 0      | 1       | 0       | 0       | 0       | 0110    |
| R                  | and         | AND                | 1      | 0      | 0       | 1       | 1       | 1       | 0000    |
| R                  | or          | OR                 | 1      | 0      | 0       | 1       | 1       | 0       | 0001    |

![ALU Control Diagram](images/alucontrol.jpg?raw=true "ALU Control Diagram")

Immediate Generator

![Immediate Generator Diagram](images/immgen.jpg?raw=true "Immediate Generator Diagram")

## RTL
After having a functional simulation in Logisim the core has been ported to Verilog to load it to a FPGA.

- The [*src*](/RTL/src/) folder contains verilog source and a text file with data memory values.

- The [*constrains*](/RTL/constrains/) folder contains the file to implement the design to the boards *Alhambra-II* and *ARTY 7 100T*.

- The [*build*](/RTL/build/) folder contains a script to synth and load the bitstream to *Alhambra-II*. Also contains Verilator generated file (Not used yet).

- The [*sim*](/RTL/sim/) file contains files used to simulate the design. In this case in Vivado simulator.

- The [*doc*](/RTL/sim/readme.md) contains documentation of the RTL design.

## Testing
To test the instructions implemented and debug the design the following assembly code has been written in [Ripes](https://github.com/mortbopet/Ripes), getting also the disassembly version of the code:

~~~assembly
#Logisim Tests
#[addr]
#(value inside)

.text
main:
    lw a0, 0 (a0)     # Load from Data[0+0](1) to x10(0)
    lw a1, 4 (a1)     # Load from Data[0+4](2) to x11(0)
    add a2, a1, a0    # Add 1 + 2 = 3 to x12
    sw a2, 4 (t0)     # Save x12(3) to Data[0+4]
    beq a2, a1, EQUAL # Don't brach x12(3) - x11(2) = 1
    sub a3, a2, a1    # Sub x12(3) - x11(2) = x13(1)
    sub a2, a2, a3    # Sub x12(3) - x13(1) = x12(2) a2 == a1
    beq a2, a1, EQUAL # Branch x12(2) - x11(2) = 0
    nop
    nop
    nop
    nop
EQUAL:
    and a3, a3, a2    # x13(1) AND x12(2) = x13(0)
    or a4, a3, a2     # x13(1) OR x12(2) = x14(1)
~~~

![Test Disassembly](images/testdisassembly.png?raw=true "Test Disassembly")

The code in hexadecimal is load to the instruction memory in Logisim. A copy of it is load in the file *textmemory*, same as a copy of the data memory in *datamemory*.

