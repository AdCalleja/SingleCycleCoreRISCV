# SingleCycleCoreRISCV

This project is intended to be a simple implementation of some of the instructions of RISC-V base ISA RV32I. The core has been designed in [Logisim](http://www.cburch.com/logisim/) as a base to understand how the processor works and it will be ported to HDL in the future.

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

1 bit ALU Control

![1 bit ALU Diagram](images/1bitalu.jpg?raw=true "1 bit ALU Diagram")

Main Control

![Main Control Diagram](images/maincontrol.jpg?raw=true "Main Control Diagram")

ALU Control

![ALU Control Diagram](images/alucontrol.jpg?raw=true "ALU Control Diagram")

Immediate Generator

![Immediate Generator Diagram](images/immgen.jpg?raw=true "Immediate Generator Diagram")

### Testing
To test the instructions implemented and debug the design the following assembly code has been written in [Ripes](https://github.com/mortbopet/Ripes), getting also the disassembly version of the code:

~~~assembly
```
#Logisim Tests

.text
main:
    lw a0, 0 (a0)
    lw a1, 8 (a1)
    add a2, a1, a0
    sw a2, 8 (t0)
    beq a2, a1, EQUAL #6 - 5
    sub a3, a2, a1 #6 - 5
    sub a2, a2, a3 #6 - 1 = 5: a2 == a1
    beq a2, a1, EQUAL
    nop
    nop
    nop
    nop
EQUAL:
    and a3, a3, a2 #1 AND 5 = 1
    or a4, a3, a2 #1 OR 5 = 5
```
~~~

![Test Disassembly](images/testdisassembly.jpg?raw=true "Test Disassembly")

The code in hexadecimal is load to the instruction memory in Logisim. A copy of it is load in the file *textmemory*, same as a copy of the data memory in *datamemory*.