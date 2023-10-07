`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/02/2023 10:44:34 PM
// Design Name: 
// Module Name: Seven_Segment
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


module Seven_Segment(
    input [9:0] sw,
    output [3:0]an,
    output [6:0]seg,
    output [9:0] led,
    output led_15
    );
    
    //Subtask A
    assign led[9:0] = sw[9:0];
    //assign an[3:0] = 4'b0010;
    //assign seg[6:0] = 7'b1010100;
    
    //Subtask B
    assign led_15 = sw[1]&sw[2]&sw[5]&sw[6]&sw[9]&~sw[8]&~sw[7]&~sw[4]&~sw[3]&~sw[0];
    
    //Subtask C an
    assign an[3:2] = 2'b00;
    assign an[1] = 1'b1;
    assign an[0] = sw[1]&sw[2]&sw[5]&sw[6]&sw[9]&~sw[8]&~sw[7]&~sw[4]&~sw[3]&~sw[0]; 
    
    //Subtask C seg
    assign seg[1:0] = 2'b00;
    assign seg[5] = 1'b0;
    assign seg[2] = ~(sw[1]&sw[2]&sw[5]&sw[6]&sw[9]&~sw[8]&~sw[7]&~sw[4]&~sw[3]&~sw[0]);
    assign seg[3] = (sw[1]&sw[2]&sw[5]&sw[6]&sw[9]&~sw[8]&~sw[7]&~sw[4]&~sw[3]&~sw[0]);
    assign seg[4] = ~(sw[1]&sw[2]&sw[5]&sw[6]&sw[9]&~sw[8]&~sw[7]&~sw[4]&~sw[3]&~sw[0]);
    assign seg[6] = ~(sw[1]&sw[2]&sw[5]&sw[6]&sw[9]&~sw[8]&~sw[7]&~sw[4]&~sw[3]&~sw[0]);
    
endmodule
