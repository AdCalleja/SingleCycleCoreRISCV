# Entity: SingleCycleCore

- **File**: SingleCycleCore.v
## Diagram

![Diagram](SingleCycleCore.svg "Diagram")
## Description



 Simple Single Cycle RISC-V core with the following instrucions implemented:
 lw, sw, beq, add, subb, and, or.

## Ports

| Port name    | Direction | Type   | Description            |
| ------------ | --------- | ------ | ---------------------- |
| original_clk | input     |        |                        |
| rst          | input     |        |                        |
| input        | input     | BUTTON |                        |
| leds         | output    | [7:0]  | Onboard Leds to Debug. |
## Signals

| Name        | Type        | Description                                                                       |
| ----------- | ----------- | --------------------------------------------------------------------------------- |
| Instruction | wire [31:0] | Instruction obtained from Text Memory for a given PC.                             |
| ReadData1   | wire [31:0] | Data from Register file 1.                                                        |
| ReadData2   | wire [31:0] | Data from Register file 2.                                                        |
| rs1         | wire [31:0] | Data for register source 1. From Register File.                                   |
| rs2         | wire [31:0] | Data for register source 2. From Register File / Immediate.                       |
| ALUOutput   | wire [31:0] | ALU output for a given operation.                                                 |
| ALUZero     | wire        | Direct 0 result from ALU.                                                         |
| DataOutput  | wire [31:0] | Data Memory output.                                                               |
| rd          | wire [31:0] | Data for register destination. Selected from ALUOutput or DataOutput.             |
| Immediate   | wire [31:0] | Immediate value generated.                                                        |
| PCPlus4     | wire [31:0] | PC + 4. Common case.                                                              |
| PCBranch    | wire [31:0] | PC + B Immediate.                                                                 |
| PCNext      | wire [31:0] | Next PC value. Selected from PCPlus4 or PCBranch.                                 |
| ALUSrc      | wire        | Select the source to ALU input ***b*** between **RegisterFile / Immediate**       |
| MemtoReg    | wire        | Select the source to Register File WriteData between **ALU Result / Data Memory** |
| RegWrite    | wire        | Enable Register File WriteEn                                                      |
| MemRead     | wire        | Enable Data Memory read                                                           |
| MemWrite    | wire        | Enable Data Memory write                                                          |
| Branch      | wire        | Select new branching program counter (if ALU also sets zero lane)                 |
| ALUOp       | wire [1:0]  | Previous instruction decodification to simplify ALUControl.                       |
| ALUCtrl     | wire [3:0]  | ALU operation selected from ALU control                                           |
| clk         | wire        |                                                                                   |
| PC          | wire [31:0] |                                                                                   |
| PCtemp      | reg [31:0]  | Internal memory state of the register.                                            |
## Processes
- ProgramCounter: ( @(posedge clk) )
  - **Type:** always
  - **Description**
  Update Program counter with the PCNext value. 
## Instantiations

- DebouncerSSC: Debouncer
- SlowClockSCC: SlowClock
- TextMemorySCC: TextMemory
- RegisterFileSCC: RegisterFile
- ImmGenSCC: ImmGen
- ALUSCC: ALU
- DataMemorySCC: DataMemory
- MainControlSCC: MainControl
- AluControlSCC: ALUControl
