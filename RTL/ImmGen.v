//! Decode instruction for every format and choose the one needed based on opcode.
module ImmGen(
    input [31:0]    Instruction,
    output reg [31:0]   Immediate
);

//! Instruction identification to select the instruction format needed
reg [6:2] Opcode;
//! S format immediate
reg [31:0] Simm;
//! B format immediate
reg [31:0] Bimm;
//! U format immediate
reg [31:0] Uimm;
//! J format immediate
reg [31:0] Jimm;   
//! I format immediate
reg [31:0] Iimm;

//! Decode muxed select of the immediate format based on the opcode of the instruction
always@(*)begin : FormatSelect
    Opcode = Instruction[6:2];

    case(Opcode)
    8: begin
        Simm = {{21{Instruction[31]}}, Instruction[30:25], Instruction[11:7]};
        Immediate = Simm;
    end
    24: begin
        Bimm = {{20{Instruction[31]}}, Instruction[7], Instruction[30:25], Instruction[11:8], 1'b0};
        Immediate = Bimm;
    end
    5,13: begin
        Uimm = {Instruction[31], Instruction[30:12], {12{1'b0}}};
        Immediate = Uimm;
    end
    27: begin
        Jimm = {{12{Instruction[31]}}, Instruction[19:12], Instruction[20], Instruction[30:21], 1'b0};   
        Immediate = Jimm;
    end
    0,3,4,25,28: begin
        Iimm = {{20{Instruction[31]}}, Instruction[31:20]};
        Immediate = Iimm;
    end
    default: Immediate = 0;
    endcase
end
endmodule
