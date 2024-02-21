`timescale 1ns / 1ps
// Create Date: 02/20/2024 10:14:11 PM
// Matric No. A0248636U

module Top_Module(input btnL, input [7:0]A, input [7:0]B, output [7:0]S, output [15:14]led);
   
    wire Carry_out_top;
    
    five_bit_adder top_adder0 (A[4:0], B[4:0], S[4:0], Carry_out_top);
    three_bit_adder top_adder1 (A[7:5], B[7:5], Carry_out_top, S[7:5]);
    
    assign led[15] = btnL;
    assign led[14] = btnL;
    
endmodule
