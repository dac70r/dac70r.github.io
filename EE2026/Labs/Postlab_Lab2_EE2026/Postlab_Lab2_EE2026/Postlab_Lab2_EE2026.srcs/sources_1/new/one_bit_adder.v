`timescale 1ns / 1ps

module one_bit_adder(input A, input B, input Carry_in, output S, output Carry_out);
    
    assign S = (A ^ B ^ Carry_in);// S is the sum of A & B & Carry_in modulus 2
    assign Carry_out = ( A & B )| (A ^ B) & Carry_in;
    
endmodule
