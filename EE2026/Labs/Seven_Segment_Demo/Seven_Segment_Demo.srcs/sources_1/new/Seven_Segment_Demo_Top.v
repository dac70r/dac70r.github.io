`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: NIL
// Engineer: Dennis Wong Guan Ming
// 
// Create Date: 02/24/2024 11:15:59 AM
// Design Name: 
// Module Name: Seven_Segment_Demo_Top
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: Demos each segment of the 7 segment LEDs. Use sw15 to sw12 to control AN3 to AN0. 
//              Use sw7 to sw0 to control DP, ....
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module Seven_Segment_Demo_Top(input [15:12]swi, input [7:0]sw, output [3:0]an, output [7:0]seg);

    assign seg = ~(sw);
    assign an[3:0] = ~(swi[15:12]);
    
endmodule
