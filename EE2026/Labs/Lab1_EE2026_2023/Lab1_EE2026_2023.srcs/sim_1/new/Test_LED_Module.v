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


module Test_LED_Module(

    );
    
    // Simulation inputs
    reg A;
    reg B;
    
    // Simulation Outputs
    wire LED1;
    wire LED2;
    wire LED3; 
    
    // Instantiation of module to be simulated
    LED_Module dut(A,B,LED1,LED2,LED3);
    
    //Stimulus 
    
    initial begin
        A=0; B=0; #10;
        A=0; B=1; #10;
        A=1; B=0; #10;
        A=1; B=1; #10;
    end
endmodule
