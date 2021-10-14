//! Main control unit. Generate control lanes based on the Opcode selected
//! and ALUOp to ALUControl.v as a 2 levels control abstraction.
module MainControl(
    input [6:0]     Opcode,     //! Opcode from Instruction
    output reg      ALUSrc,     //! Select the source to ALU input ***b*** between **RegisterFile / Immediate**
    output reg      MemtoReg,   //! Select the source to Register File WriteData between **ALU Result / Data Memory**
    output reg      RegWrite,   //! Enable Register File WriteEn
    output reg      MemRead,    //! Enable Data Memory read
    output reg      MemWrite,   //! Enable Data Memory write
    output reg      Branch,     //! Select new branching program counter (if ALU also sets zero lane)
    output reg [1:0] ALUOp      //! Previous instruction decodification to simplify ALUControl.
);

always@(*)begin : OpcodeDecode
    case(Opcode)
    //R-format
    7'b0110011:  begin
        ALUSrc = 0;
        MemtoReg = 0;
        RegWrite = 1;
        MemRead = 0;
        MemWrite = 0;
        Branch = 0;
        ALUOp = 2'b10;
    end
    //lw
    7'b0000011:  begin
        ALUSrc = 1;
        MemtoReg = 1;
        RegWrite = 1;
        MemRead = 1;
        MemWrite = 0;
        Branch = 0;
        ALUOp = 2'b00;
    end
    //sw
    7'b0100011:  begin
        ALUSrc = 1;
        MemtoReg = 0; //x
        RegWrite = 0;
        MemRead = 0;
        MemWrite = 1;
        Branch = 0;
        ALUOp = 2'b00;
    end
    //beq
    7'b1100011:  begin
        ALUSrc = 0;
        MemtoReg = 0; //x
        RegWrite = 0;
        MemRead = 0;
        MemWrite = 0;
        Branch = 1;
        ALUOp = 2'b01;
    end
    
    default:  begin
        ALUSrc = 0;
        MemtoReg = 0;
        RegWrite = 0;
        MemRead = 0;
        MemWrite = 0;
        Branch = 0;
        ALUOp = 0;
    end
    endcase
end

endmodule
