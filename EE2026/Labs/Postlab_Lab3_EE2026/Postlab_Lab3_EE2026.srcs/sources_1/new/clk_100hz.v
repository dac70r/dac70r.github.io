`timescale 1ns / 1ps

module clk_100hz(input main_clock, output reg clk_100hz);

reg [31:0] clk_100hz_count = 0;
reg clk_100hz_output = 0;
    
always @ (posedge main_clock)
    begin
        clk_100hz_count <= clk_100hz_count + 1;
        if(clk_100hz_count == 50_000_0)
        begin
            clk_100hz_count <= 0;
            clk_100hz_output <= ~clk_100hz_output;
            clk_100hz <= clk_100hz_output;
        end        
    end

endmodule
