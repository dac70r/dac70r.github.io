`timescale 1ns / 1ps
// Create Date: 02/20/2024 10:17:13 PM

module five_bit_adder( input [4:0]A, input [4:0]B, output [4:0]S , output Carry_out);
    
    reg Carry_in = 0;
    wire [3:0] Carry_out_within;
    
    one_bit_adder adder0 ( A[0], B[0], Carry_in, S[0], Carry_out_within[0]);
    one_bit_adder adder1 ( A[1], B[1], Carry_out_within[0], S[1], Carry_out_within[1]);
    one_bit_adder adder2 ( A[2], B[2], Carry_out_within[1], S[2], Carry_out_within[2]);
    one_bit_adder adder3 ( A[3], B[3], Carry_out_within[2], S[3], Carry_out_within[3]);
    one_bit_adder adder4 ( A[4], B[4], Carry_out_within[3], S[4], Carry_out);
    
endmodule
