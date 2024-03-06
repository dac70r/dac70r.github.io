`timescale 1ns / 1ps


module clk_1hz(input main_clock, output reg clk_1hz, output reg [1:0] count_subtaskC_1hz = 0);

reg [25:0] clk_1hz_count = 0; // 26-bit counter
reg clk_1hz_output = 0;
    
always @ (posedge main_clock)
    begin
        clk_1hz_count <= clk_1hz_count + 1;
        if(clk_1hz_count == 50_000_000)
        begin
            clk_1hz_count <= 0;
            clk_1hz_output <= ~clk_1hz_output;
            clk_1hz <= clk_1hz_output;
            if(count_subtaskC_1hz == 2) begin count_subtaskC_1hz <= 0; end
            else begin count_subtaskC_1hz <= count_subtaskC_1hz + 1; end
        end        
    end
    
endmodule
