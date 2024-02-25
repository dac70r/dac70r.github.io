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


module Seven_Segment_Demo_Top(input CLK100MHZ, input [15:12]swi, input [6:0]sw, output [3:0]an, output  [6:0]seg, output dp);

    reg one = 7'b1111001;
    reg two = 7'b0100100;
    reg three = 7'b0110000;
    reg four = 7'b0011001;
    reg five = 7'b0010010;
    reg six = 7'b0000010;
    reg seven = 7'b1111000;
    reg eight = 7'b0000000;
    reg nine = 7'b0010000;
    reg zero = 7'b1000000;
    
reg [27:0] counter = 0; // 1hz clock
reg led_output = 0;
    
    always @ (posedge CLK100MHZ)
    begin
         if(counter == 99_999_999)
         begin
            led_output <= ~led_output;
            counter <= 0;
         end
         else
            counter <= counter + 1;
    end 
       
    assign seg[6:0] = ~(sw[6:0]);
    assign an[3:0] = ~(swi[15:12]);
    assign dp = led_output;
    
endmodule
