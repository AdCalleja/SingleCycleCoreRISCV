//! Decode instruction for every format and choose the one needed based on opcode.
module ImmGen(
    input [31:0]    Instruction,
    output reg [31:0]   Immediate
);

//! Instruction identification to select the instruction format needed
wire [6:2] Opcode = Instruction[6:2];
//! S format immediate
wire [31:0] Simm = {{21{Instruction[31]}}, Instruction[30:25], Instruction[11:7]};
//! B format immediate
wire [31:0] Bimm = {{20{Instruction[31]}}, Instruction[7], Instruction[30:25], Instruction[11:8], 1'b0};
//! U format immediate
wire [31:0] Uimm = {Instruction[31], Instruction[30:12], {12{1'b0}}};
//! J format immediate
wire [31:0] Jimm = {{12{Instruction[31]}}, Instruction[19:12], Instruction[20], Instruction[30:21], 1'b0};   
//! I format immediate
wire [31:0] Iimm = {{21{Instruction[31]}}, Instruction[30:20]};

//! Decode muxed select of the immediate format based on the opcode of the instruction
always@(*)begin : FormatSelect
    case(Opcode)
    8: Immediate <= Simm;
    24: Immediate <= Bimm;
    5,13: Immediate <= Uimm;
    27: Immediate <= Jimm;
    0,3,4,25,28: Immediate <= Iimm;
    default: Immediate <= 0;
    endcase
end
endmodule