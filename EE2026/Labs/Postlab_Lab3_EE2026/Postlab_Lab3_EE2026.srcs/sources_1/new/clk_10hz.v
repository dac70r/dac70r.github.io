`timescale 1ns / 1ps

module clk_10hz(input main_clock, output reg clk_10hz, output reg [1:0] count_subtaskC_10hz = 0);

reg [22:0] clk_10hz_count = 0; // 22-bit counter
reg clk_10hz_output = 0;
    
always @ (posedge main_clock)
    begin
        clk_10hz_count <= clk_10hz_count + 1;
        if(clk_10hz_count == 50_000_00)
        begin
            clk_10hz_count <= 0;
            clk_10hz_output <= ~clk_10hz_output;
            clk_10hz <= clk_10hz_output;
            if(count_subtaskC_10hz == 2) begin count_subtaskC_10hz <= 0; end
            else begin count_subtaskC_10hz <= count_subtaskC_10hz + 1; end
        end        
    end

endmodule
