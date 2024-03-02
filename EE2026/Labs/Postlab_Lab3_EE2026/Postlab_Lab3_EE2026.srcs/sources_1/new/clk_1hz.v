`timescale 1ns / 1ps


module clk_1hz(input main_clock, output reg clk_1hz);

reg [31:0] clk_1hz_count = 0;
reg clk_1hz_output = 0;
    
always @ (posedge main_clock)
    begin
        clk_1hz_count <= clk_1hz_count + 1;
        if(clk_1hz_count == 50_000_000)
        begin
            clk_1hz_count <= 0;
            clk_1hz_output <= ~clk_1hz_output;
            clk_1hz <= clk_1hz_output;
        end        
    end
    
endmodule
