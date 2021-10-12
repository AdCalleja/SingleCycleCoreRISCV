//`include "/home/adrian/codigo/RISC-V/SingleCycleCoreRISCV/RTL/ALU.v"
`include "ALU.v"
`include "ALUControl.v"
`include "DataMemory.v"
`include "ImmGen.v"
`include "MainControl.v"
`include "RegisterFile.v"
`include "TextMemory.v"
//Debouncer
`include "Debouncer.v"

//! Simple Single Cycle RISC-V core with the following instrucions implemented:
//! lw, sw, beq, add, subb, and, or.
module SingleCycleCore(
    input   original_clk,
    input   rst,
    input   btn,
    output [7:0] leds     //! Onboard Leds to Debug.
);

//MEMORY PARAMETERS
//localparam ROM_ADDR_WIDTH = 8;  //! Text Memory address width (hence deep).
//localparam RAM_ADDR_WIDTH = 8;  //! Data Memory address width (hence deep).

//DATAPATH WIRES
wire [31:0] Instruction;    //! Instruction obtained from Text Memory for a given PC.
wire [31:0] ReadData1;      //! Data from Register file 1.
wire [31:0] ReadData2;      //! Data from Register file 2.
wire [31:0] rs1;            //! Data for register source 1. From Register File.
wire [31:0] rs2;            //! Data for register source 2. From Register File / Immediate.
wire [31:0] ALUOutput;      //! ALU output for a given operation.
wire        ALUZero;        //! Direct 0 result from ALU.
wire [31:0] DataOutput;     //! Data Memory output.
wire [31:0] rd;             //! Data for register destination. Selected from ALUOutput or DataOutput.
wire [31:0] Immediate;      //! Immediate value generated.
wire [31:0] PCPlus4;        //! PC + 4. Common case.
wire [31:0] PCBranch;       //! PC + B Immediate.
wire [31:0] PCNext;         //! Next PC value. Selected from PCPlus4 or PCBranch.

//CONTROL WIRES
//Directly get from instruction
//wire [6:0]  Opcode;           //! Opcode extracted from Instruction[6:0]. Used to generate Main Control lines.
wire ALUSrc;                //! Select the source to ALU input ***b*** between **RegisterFile / Immediate**
wire MemtoReg;              //! Select the source to Register File WriteData between **ALU Result / Data Memory**
wire RegWrite;              //! Enable Register File WriteEn
wire MemRead;               //! Enable Data Memory read
wire MemWrite;              //! Enable Data Memory write
wire Branch;                //! Select new branching program counter (if ALU also sets zero lane)
wire [1:0]  ALUOp;          //! Previous instruction decodification to simplify ALUControl.
wire [3:0]  ALUCtrl;        //! ALU operation selected from ALU control

//Button Clock Debouncer
wire clk;
Debouncer DebouncerSSC(.clk(original_clk), .btn(btn), .btn_out(clk));

//  --DATAPATH--

//PROGRAM COUNTER
wire [31:0] PC;
reg [31:0]  PCtemp;    //! Internal memory state of the register.
//! Update Program counter with the PCNext value.
always @(posedge clk) begin : ProgramCounter
    if (rst == 0) begin
        PCtemp <= PCNext;
    end
    else begin
        PCtemp <= 0;
    end   
end
assign PC = PCtemp;
// Next PC -  Branch Control
assign PCNext = (Branch & ALUZero) ? PCBranch : PCPlus4;
assign PCPlus4 = PC + 4;
assign PCBranch = PC + Immediate;

// TEXT MEMORY
//#(.ADDR_WIDTH(8)) 
TextMemory TextMemorySCC (
        .addr(PC[9:2]), 
        .data_out(Instruction));

// REGISTER FILE
RegisterFile RegisterFileSCC(
    .clk(clk), 
    .rst(rst), 
    .WriteDir(Instruction[11:7]), 
    .WriteEn(RegWrite), 
    .WriteData(rd), 
    .ReadDir1(Instruction[19:15]), 
    .ReadDir2(Instruction[24:20]), 
    .ReadData1(ReadData1), 
    .ReadData2(ReadData2));
assign rs1 = ReadData1;
assign rs2 = ALUSrc ? Immediate : ReadData2;
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
//#(.ADDR_WIDTH(8)) 
DataMemory DataMemorySCC(
        .clk(clk),
        .data_in(ReadData2),
        .addr(ALUOutput[9:2]),
        .we(MemWrite),
        .re(MemRead),
        .data_out(DataOutput));

// rd MUX
assign rd = MemtoReg ? DataOutput : ALUOutput;


// --CONTROL--

// MAIN CONTROL
MainControl MainControlSCC(
    .Opcode(Instruction[6:0]), 
    .ALUSrc(ALUSrc), 
    .MemtoReg(MemtoReg), 
    .RegWrite(RegWrite), 
    .MemRead(MemRead), 
    .MemWrite(MemWrite),
    .Branch(Branch), 
    .ALUOp(ALUOp));

// ALU CONTROL
ALUControl AluControlSCC(
    .ALUOp(ALUOp), 
    .Func7(Instruction[30]), 
    .Func3(Instruction[14:12]), 
    .ALUCtrl(ALUCtrl));

assign leds[0] = ALUOutput[0] | ALUOutput[8] | ALUOutput[16] | ALUOutput[24]; 
assign leds[1] = ALUOutput[1] | ALUOutput[9] | ALUOutput[17] | ALUOutput[25];
assign leds[2] = ALUOutput[2] | ALUOutput[10] | ALUOutput[18] | ALUOutput[26];
assign leds[3] = ALUOutput[3] | ALUOutput[11] | ALUOutput[19] | ALUOutput[27];
assign leds[4] = ALUOutput[4] | ALUOutput[12] | ALUOutput[20] | ALUOutput[28];
assign leds[5] = ALUOutput[5] | ALUOutput[13] | ALUOutput[21] | ALUOutput[29];
assign leds[6] = ALUOutput[6] | ALUOutput[14] | ALUOutput[22] | ALUOutput[30];
assign leds[7] = ALUOutput[7] | ALUOutput[15] | ALUOutput[23] | ALUOutput[31];

endmodule
