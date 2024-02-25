`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: Dennis Wong
// 
// Create Date: 02/24/2024 11:22:15 PM
// Design Name: 
// Module Name: mux_decision
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


module mux_decision(
    input [1:0]S,
    output [1:0]Z
    );
    
    wire S_within;
    
    is_msb_bit mux1(~S[1],S_within, S[1], Z[1]);
    is_msb_bit mux0(~S[0],S_within[2], S[0], Z[0]);

    
endmodule
