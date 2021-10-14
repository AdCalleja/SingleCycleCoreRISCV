module SingleCycleCore_tb();

reg original_clk;
reg rst;
reg btn;
wire [7:0] leds;

SingleCycleCore U0(
    .original_clk(original_clk),
    .rst(rst),
    .btn(btn),
    .leds(leds)
);

initial begin
    original_clk = 0;
    rst = 0;
    btn = 0;
    rst = 1;
    #180000 rst = 0;
end

always begin
    #1 original_clk = !original_clk;  
end

always begin
    #30500 btn = !btn;
end

endmodule