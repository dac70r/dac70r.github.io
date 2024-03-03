`timescale 1ns / 1ps

module clk_4hz(input main_clock, output clk_4hz);

reg [23:0] clk_4hz_count = 0; // 24-bit counter
reg clk_4hz_output = 0;
    
always @ (posedge main_clock)
    begin
        clk_4hz_count <= clk_4hz_count + 1;
        if(clk_4hz_count == 12_500_000)
        begin
            clk_4hz_count <= 0;
            clk_4hz_output <= ~clk_4hz_output;
        end        
    end
    
assign clk_4hz = clk_4hz_output;
endmodule