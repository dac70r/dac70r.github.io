`timescale 1ns / 1ps

module clk_1hz_subtaskD(input main_clock, 
                input master_switch,
                output reg raised = 1'b0);

// Declare counters for the 1hz clock
reg [28:0] clk_1hz_count = 0; // 29-bit counter
reg clk_1hz_output = 0;

always @ (posedge main_clock)
begin
    // If the master switch opens, then only we proceed to increment 3 second counter
    if(master_switch == 1)
        begin
            clk_1hz_count <= clk_1hz_count + 1;
            // We raise the "raised" flag, we don't care about the value of clk_1hz_count after this
            if(clk_1hz_count == 300_000_000)
                begin
                    raised <= 1;
                end
        end
    else
        // If the master switch not open, or if it was closed, we revert the value of "raised" & count_subtaskC_1hz back to 0;
        begin raised <= 0; clk_1hz_count <= 0; end
end
    
endmodule


