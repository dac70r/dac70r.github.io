////  `timescale 1ns / 1ps
   
//module my_sim();

//// Simulation Inputs
//reg btnL;
//reg [7:0]A;
//reg [7:0]B;

//// Simulation Outputs
//wire [6:0]seg;
//wire [3:0]an;
//wire [7:0]S;
//wire [1:0]led




//endmodule

`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/02/2023 10:02:51 PM
// Design Name: 
// Module Name: Test_LED_Module
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


module my_sim(

    );
    
    // Simulation inputs
    reg btnL;
    reg [7:0]A;
    reg [7:0]B;
    
    // Simulation Outputs
    wire [3:0]an;
    wire [6:0]seg;
    wire [7:0]S;
    wire [1:0]led; 
    
    // Instantiation of module to be simulated
    //Top_Module(input btnL, input [7:0]A, input [7:0]B, output reg [6:0]seg =7'b0111_110, output reg [3:0]an=4'b0011, output [7:0]S, output [15:14]led);
    //Top_Module dut(btnL,A[7:0],B[7:0],seg[6:0],an[3:0],S[7:0],led[1:0]);
    Top_Module dut(.btnL(btnL),.A(A),.B(B),.seg(seg),.an(an),.S(S),.led(led));
    
    //Stimulus 
    
    initial begin
        btnL=0; A[7]=0; A[6]=0; A[5]=0; A[4]=0; A[3]=0; A[2]=0; A[1]=0; A[0]=0;
        B[7]=0; B[6]=0; B[5]=0; B[4]=0; B[3]=0; B[2]=0; B[1]=0; B[0]=0; #10;
        //btnL=0; A[7:0]=8'b0000_0011; B[7:0]=8'b0000_0011; #10;
//        A=1; B=0; #10;
//        A=1; B=1; #10;
    end
endmodule
