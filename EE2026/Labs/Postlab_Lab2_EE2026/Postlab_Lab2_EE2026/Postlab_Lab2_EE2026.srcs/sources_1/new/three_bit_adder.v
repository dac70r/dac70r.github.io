`timescale 1ns / 1ps

module three_bit_adder(input [2:0]A, input [2:0]B, input Carry_in, output [2:0]S);
    //one_bit_adder(input A, input B, input Carry_in, output S, output Carry_out);
    
    wire [1:0]Carry_out_within;
    wire Carry_out; 
    
    one_bit_adder adder0 ( A[0],B[0],Carry_in, S[0], Carry_out_within[0]);
    one_bit_adder adder1 ( A[1],B[1],Carry_out_within[0], S[1], Carry_out_within[1]);
    one_bit_adder adder2 ( A[2],B[2],Carry_out_within[1], S[2], Carry_out);
    
endmodule
