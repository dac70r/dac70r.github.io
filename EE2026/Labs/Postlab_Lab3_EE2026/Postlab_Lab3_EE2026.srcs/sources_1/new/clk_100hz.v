`timescale 1ns / 1ps

module clk_100hz(input main_clock, output reg clk_100hz, output reg [1:0] count_subtaskC_100hz = 0);

reg [18:0] clk_100hz_count = 0; // 19-bit counter
reg clk_100hz_output = 0;
    
always @ (posedge main_clock)
    begin
        clk_100hz_count <= clk_100hz_count + 1;
        if(clk_100hz_count == 50_000_0)
        begin
            clk_100hz_count <= 0;
            clk_100hz_output <= ~clk_100hz_output;
            clk_100hz <= clk_100hz_output;
            if(count_subtaskC_100hz == 2) begin count_subtaskC_100hz <= 0; end
            else begin count_subtaskC_100hz <= count_subtaskC_100hz + 1; end
        end        
    end

endmodule
