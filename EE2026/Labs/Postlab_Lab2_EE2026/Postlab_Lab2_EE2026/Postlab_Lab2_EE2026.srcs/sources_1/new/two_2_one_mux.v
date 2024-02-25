`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: Dennis Wong
// 
// Create Date: 02/24/2024 10:39:36 PM
// Design Name: 
// Module Name: two_2_one_mux
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


module is_msb_bit (input A, input B, input C, output D);

    assign D = C ? A : B; // assign negation of D to D if C is msb. Else, assign normal D to D. 
    
endmodule

