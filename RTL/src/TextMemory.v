module TextMemory #(
  parameter DATA_WIDTH=32,          //width of data bus
  parameter ADDR_WIDTH=8           //width of addresses buses
)(
  input  [(ADDR_WIDTH-1):0] addr,  //address for write/read operation
  output reg [(DATA_WIDTH-1):0] data_out      //read data
);

//! Internal memory instantation
//reg [(DATA_WIDTH-1):0] rom[2**ADDR_WIDTH-1:0];

always@(*)
begin
    case(addr)
        0: data_out = 32'h00052503;
        1: data_out = 32'h0045a583;
        2: data_out = 32'h00a58633;
        3: data_out = 32'h00c2a223;
        4: data_out = 32'h02b60063;
        5: data_out = 32'h40b606b3;
        6: data_out = 32'h40d60633;
        7: data_out = 32'h00b60a63;
        'h0C: data_out = 32'h00c6f6b3;
        'h0D: data_out = 32'h00c6e733;

        default: data_out = 32'h00000000;
    endcase
end

//Program memory established manually
//assign rom[0] = 32'h00052503;
//assign rom[4] = 32'h0085a583;
//assign rom[8] = 32'h00a58633;
//assign rom[12] = 32'h00c2a423;
//assign rom[16] = 32'h02b60063;
//assign rom[20] = 32'h40b606b3;
//assign rom[24] = 32'h40d60633;
//assign rom[28] = 32'h00b60a63;

//assign data_out = rom[addr];
endmodule
