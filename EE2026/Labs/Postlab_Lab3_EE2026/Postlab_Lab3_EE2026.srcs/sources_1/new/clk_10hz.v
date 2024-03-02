`timescale 1ns / 1ps

module clk_10hz(input main_clock, output reg clk_10hz);
reg [31:0] clk_10hz_count = 0;
reg clk_10hz_output = 0;
    
always @ (posedge main_clock)
    begin
        clk_10hz_count <= clk_10hz_count + 1;
        if(clk_10hz_count == 50_000_00)
        begin
            clk_10hz_count <= 0;
            clk_10hz_output <= ~clk_10hz_output;
            clk_10hz <= clk_10hz_output;
        end        
    end

endmodule
