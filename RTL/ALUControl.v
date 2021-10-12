//! Generate signal to control ALU based on the main control line ALUOp + 
//! instruction decodificated Func7 + Func3.
//! | Instruction Format | Instruction | Desired ALU action | ALUOp1 | ALUOp0 | I\[30\] | I\[14\] | I\[13\] | I\[12\] | ALUCtrl |
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
    output reg [3:0]    ALUCtrl
);
wire [3:0] Func;
assign Func = {Func7,Func3};
always@(*)begin : AluControl
    case(ALUOp)
    //Addition
    2'b00:  ALUCtrl = 4'b0010;
    //Substraction
    2'b01:  ALUCtrl = 4'b0110;
    //To be Determined
    2'b10:  begin
        case(Func)
            4'b0000: ALUCtrl = 4'b0010;    //add
            4'b1000: ALUCtrl = 4'b0110;    //sub
            4'b0111: ALUCtrl = 4'b0000;    //and
            4'b0110: ALUCtrl = 4'b0001;    //or
            default: ALUCtrl = 4'b0000;
        endcase
    end
    default: ALUCtrl = 4'b0000;
    //0'b11 not used
    endcase
end

endmodule
