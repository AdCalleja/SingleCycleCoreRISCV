//! Clock slower by counting pulses
module SlowClock(input clk, output slow_clk);
    reg [23:0] counter = 0;     //Limit of the counter 16 777 216

    always @(posedge clk) begin
        //2.5ms (400 pulses/sec)
        //Alhambra-ii   12MHz -> counter limit = 30000 -> 29999
        //Arty 7        100MHz -> counter limit = 250000 -> 249999
        //1s (400 pulses/sec)
        //Alhambra-ii   12MHz -> counter limit = 12000000 -> 11999999
        counter <= (counter>=11999999) ? 0 : counter+1;    
    end

    assign slow_clk = (counter == 11999999) ? 1'b1 : 1'b0;
endmodule
