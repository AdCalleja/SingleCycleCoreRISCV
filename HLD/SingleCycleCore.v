`include "/home/adrian/codigo/RISC-V/SingleCycleCoreRISCV/HLD/ALU.v"
`include "/home/adrian/codigo/RISC-V/SingleCycleCoreRISCV/HLD/ALUControl.v"
`include "/home/adrian/codigo/RISC-V/SingleCycleCoreRISCV/HLD/DataMemory.v"
`include "/home/adrian/codigo/RISC-V/SingleCycleCoreRISCV/HLD/ImmGen.v"
`include "/home/adrian/codigo/RISC-V/SingleCycleCoreRISCV/HLD/MainControl.v"
`include "/home/adrian/codigo/RISC-V/SingleCycleCoreRISCV/HLD/RegisterFile.v"
`include "/home/adrian/codigo/RISC-V/SingleCycleCoreRISCV/HLD/TextMemory.v"

//! Simple Single Cycle RISC-V core with the following instrucions implemented:
//! lw, sw, beq, add, subb, and, or.
module top(
    input   clk,
    input   rst,
    output [7:0] leds     //! Onboard Leds to Debug.
);

//MEMORY PARAMETERS
localparam ROM_ADDR_WIDTH = 8;  //! Text Memory address width (hence deep).
localparam RAM_ADDR_WIDTH = 8;  //! Data Memory address width (hence deep).

//DATAPATH WIRES
wire [31:0] Instruction;    //! Instruction obtained from Text Memory for a given PC.
wire [31:0] rs1;            //! Data for register source 1. Output of Register File.
wire [31:0] rs2;            //! Data for register source 2. Output of Register File.
wire [31:0] ALUOutput;      //! ALU output for a given operation.
wire        ALUZero;        //! Direct 0 result from ALU.
wire [31:0] DataOutput;     //! Data Memory output.
wire [31:0] rd;             //! Data for register destination. Selected from ALUOutput or DataOutput.
wire [31:0] Immediate;      //! Immediate value generated.
wire [31:0] PCPlus4;        //! PC + 4. Common case.
wire [31:0] PCBranch;       //! PC + B Immediate.
wire [31:0] PCNext;         //! Next PC value. Selected from PCPlus4 or PCBranch.

//CONTROL WIRES
wire [6:0]Opcode;           //! Opcode extracted from Instruction[6:0]. Used to generate Main Control lines.
wire ALUSrc;                //! Select the source to ALU input ***b*** between **RegisterFile / Immediate**
wire MemtoReg;              //! Select the source to Register File WriteData between **ALU Result / Data Memory**
wire RegWrite;              //! Enable Register File WriteEn
wire MemRead;               //! Enable Data Memory read
wire MemWrite;              //! Enable Data Memory write
wire Branch;                //! Select new branching program counter (if ALU also sets zero lane)
wire [1:0]  ALUOp;          //! Previous instruction decodification to simplify ALUControl.
wire [3:0]  ALUCtrl;        //! ALU operation selected from ALU control


//  --DATAPATH--

//PROGRAM COUNTER
reg [31:0]  PC;    //! Internal memory state of the register.
//! Update Program counter with the PCNext value.
always @(posedge clk) begin : ProgramCounter
    if (rst == 0) begin
        PC <= PCNext;
    end
    else begin
        PC <= 0;
    end
        
end
// Next PC -  Branch Control
assign PCNext = (Branch & ALUZero) ? PCBranch : PCPlus4;
assign PCPlus4 = PC + 4;
assign PCBranch = PC + Immediate;

// TEXT MEMORY
TextMemoryROM #(.ADDR_WIDTH(ROM_ADDR_WIDTH)) 
    TextMemoryROMSCC (
        .addr(PC[9:2]), 
        .data_out(Instruction));

// REGISTER FILE
RegisterFile RegisterFileSCC(
    .clk(clk), .rst(rst), 
    .WriteDir(Instruction[11:7]), 
    .WriteEn(RegWrite), 
    .WriteData(rd), 
    .ReadDir1(Instruction[19:15]), 
    .ReadDir2(Instruction[24:20]), 
    .ReadData1(rs1), 
    .ReadData2(rs2));

// IMMEDIATE GENERATOR
ImmGen ImmGenSCC(
    .Instruction(Instruction), 
    .Immediate(Immediate));

// ALU
ALU ALUSCC(
    .a(rs1),
    .b(rs2),
    .ALUCtrl(ALUCtrl),
    .Result(ALUOutput),
    .ALUZero(ALUZero));

// DATA MEMORY
DataMemoryRAM #(.ADDR_WIDTH(RAM_ADDR_WIDTH)) 
    DataMemoryRAMSCC(
        .clk(clk),
        .data_in(rs2),
        .addr(ALUOutput[9:2]),
        .we(MemWrite),
        .data_out(DataOutput));

// rd MUX
assign rd = MemtoReg ? DataOutput : ALUOutput;


// --CONTROL--

// MAIN CONTROL
MainControl MainControlSCC(
    .Opcode(Opcode), 
    .ALUSrc(ALUSrc), 
    .MemtoReg(MemtoReg), 
    .RegWrite(RegWrite), 
    .MemRead(MemRead), 
    .Branch(Branch), 
    .ALUOp(ALUOp));

// ALU CONTROL
ALUControl AluControSCC(
    .ALUOp(ALUOp), 
    .Func7(Instruction[30]), 
    .Func3(Instruction[14:12]), 
    .ALUCtrl(ALUCtrl));

assign leds = rd[7:0];

endmodule