`include "/home/adrian/codigo/RISC-V/SingleCycleCoreRISCV/HLD/ALU.v"
`include "/home/adrian/codigo/RISC-V/SingleCycleCoreRISCV/HLD/ALUControl.v"
`include "/home/adrian/codigo/RISC-V/SingleCycleCoreRISCV/HLD/DataMemory.v"
`include "/home/adrian/codigo/RISC-V/SingleCycleCoreRISCV/HLD/ImmGen.v"
`include "/home/adrian/codigo/RISC-V/SingleCycleCoreRISCV/HLD/MainControl.v"
`include "/home/adrian/codigo/RISC-V/SingleCycleCoreRISCV/HLD/RegisterFile.v"
`include "/home/adrian/codigo/RISC-V/SingleCycleCoreRISCV/HLD/TextMemory.v"

module SingleCycleCore #(
    parameter ROM_DATA_WIDTH=32,          //width of data bus
    parameter ROM_ADDR_WIDTH=8,
    parameter RAM_DATA_WIDTH=32,          //width of data bus
    parameter RAM_ADDR_WIDTH=8
)
(
    input   clk,
    input   rst
);

//PROGRAM COUNTER
reg [31:0]  PC;    //! Internal memory state of the register
wire [31:0] PCout;
reg [31:0]  NewPC;
//! Write PC
always @(posedge clk) begin : ProgramCounter
    if (rst == 0) begin
        PC <= NewPC;
    end
    else begin
        PC <= 3;
    end
        
end
//! Read PC
//assign PCout = PC;
//COMPROBAR SI PC FUNCIONA. NO DEBER'IA PODERSE INCLUIR UN REG COMO ENTRADA A .addr
wire [31:0] Instruction;
TextMemoryROM #(.ADDR_WIDTH(ROM_ADDR_WIDTH)) TextMemoryROM1 (.addr(PC[9:2]), .data_out(Instruction));

endmodule