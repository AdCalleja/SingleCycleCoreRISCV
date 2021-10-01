//! Generate signal to control ALU based on the main control line ALUOp + 
//! instruction decodificated Func7 + Func3.
//! | Instruction Format | Instruction | Desired ALU action | ALUOp1 | ALUOp0 | I\[30\] | I\[14\] | I\[13\] | I\[12\] | AluCtrl |
//! | ------------------ | ----------- | ------------------ | ------ | ------ | ------- | ------- | ------- | ------- | ------- |
//! | I                  | lw          | add                | 0      | 0      | x       | x       | x       | x       | 0010    |
//! | S                  | sw          | add                | 0      | 0      | x       | x       | x       | x       | 0010    |
//! | B                  | beq         | substract          | 0      | 1      | x       | x       | x       | x       | 0110    |
//! | R                  | add         | add                | 1      | 0      | 0       | 0       | 0       | 0       | 0010    |
//! | R                  | sub         | substract          | 1      | 0      | 1       | 0       | 0       | 0       | 0110    |
//! | R                  | and         | AND                | 1      | 0      | 0       | 1       | 1       | 1       | 0000    |
//! | R                  | or          | OR                 | 1      | 0      | 0       | 1       | 1       | 0       | 0001    |

module ALUControl(
    input [1:0]     ALUOp,  //! From MainControl
    input           Func7,  //! From instruction
    input [2:0]     Func3,  //! From instruction
    output reg [3:0]    AluCtrl
);

always@(*)begin : AluControl
    case(ALUOp)
    //Addition
    4'b00:  AluCtrl <= 4'b0010;
    //Substraction
    4'b01:  AluCtrl <= 4'b0110;
    //To be Determined
    4'b10:  begin
        case(Func7&Func3)
            4'b0000: AluCtrl <= 4'b0000;
            4'b0000: AluCtrl <= 4'b1000;
            4'b0000: AluCtrl <= 4'b0111;
            4'b0000: AluCtrl <= 4'b0110;
            default: AluCtrl <= 4'b0000;
        endcase
    end
    default: AluCtrl <= 4'b0000;
    //0'b11 not used
    endcase
end

endmodule