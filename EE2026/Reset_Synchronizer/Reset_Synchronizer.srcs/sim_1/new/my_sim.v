`timescale 1ns / 1ps

module my_sim;

reg async_reset; // Asynchronous reset signal
reg clk;         // Clock signal
wire sync_reset;   // Synchronized reset signal

// Unit under test
Reset_Synchronizer uut (async_reset, clk, sync_reset);

initial
begin
    clk = 0;
    async_reset = 1;
end

always #3 clk = ~clk;
//always #10 async_reset = ~async_reset;

initial begin
    #21; // Wait for 10 time units
    async_reset = 0;
    #1; // Wait for 10 time units
    async_reset = 1;
end


endmodule
