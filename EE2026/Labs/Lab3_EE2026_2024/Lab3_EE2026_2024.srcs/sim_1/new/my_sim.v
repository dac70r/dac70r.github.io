`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/27/2024 10:55:11 PM
// Design Name: 
// Module Name: my_simulation
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module test_blinky();
    reg clock; wire led;
    
    blinky dut (clock, led);
    
    initial begin
        clock = 1;
    end
    
    always begin
        #5 clock = ~clock;
    end

endmodule
