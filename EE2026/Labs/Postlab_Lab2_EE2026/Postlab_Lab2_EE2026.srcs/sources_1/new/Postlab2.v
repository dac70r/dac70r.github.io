`timescale 1ns / 1ps
// Create Date: 02/20/2024 10:14:11 PM
// Matric No. A0248636U
// Company: NUS
// Engineer: Dennis Wong Guan Ming
// 
// Create Date: 02/24/2024 10:39:36 PM

module Top_Module(input btnL, input [7:0]A, input [7:0]B, output reg [6:0]seg =7'b0111_110, output reg [3:0]an=4'b0011, output [7:0]S, output [15:14]led);
   
    wire Carry_out_top;
    wire [7:0] S_inside;
    wire [7:0] is_msb_flag; 
    
    five_bit_adder top_adder0 (A[4:0], B[4:0], S_inside[4:0], Carry_out_top);
    three_bit_adder top_adder1 (A[7:5], B[7:5], Carry_out_top, S_inside[7:5]);
   
    assign is_msb_flag = S_inside; 
    assign S[7] = (btnL) ? (is_msb_flag[7] ? ~S_inside[7] : S_inside[7] ) : S_inside[7];
    // if button not pressed S[7] = S_inside[7], else is_msb_flag[7] asserted, yes -> S[7] = ~S_inside[7], no -> S[7] = S_inside[7] 
    assign S[6] = (btnL) ? 
        /* if is_msb_flag[7] is asserted invert s6 directly*/ (is_msb_flag[7] ? ~S_inside[6] : 
        /* else check if is_msb_flag[6] is asserted */ (is_msb_flag[6] ? ~S_inside[6] : S_inside[6] )) : S_inside[6];
        
    assign S[5] = (btnL) ? (is_msb_flag[7] ? S_inside[5] : (is_msb_flag[6] ? ~S_inside[5] : (is_msb_flag[5] ? ~S_inside[5] : S_inside[5] ))) : S_inside[5];
        /* if is_msb_flag[7] is asserted then s[5] = s_inside[5] (do nothing)*/
        /* if is_msb_flag[6] is asserted invert s5 directly */ 
        /* else check if is_msb_flag[5] is asserted */ 
        
    assign S[4] = (btnL) ? 
    (is_msb_flag[6] | is_msb_flag[7] ? S_inside[4] : (is_msb_flag[5] ? ~S_inside[4] : (is_msb_flag[4] ? ~S_inside[4] : S_inside[4] ))) : S_inside[4];
        /* if is_msb_flag[7] is asserted then s[4] = s_inside[4] (do nothing) */
        /* if is_msb_flag[6] is asserted then s[4] = s_inside[4] (do nothing) */
        /* if is_msb_flag[5] is asserted invert s4 directly */ 
        /* else check if is_msb_flag[4] is asserted */   
    
    assign S[3] = (btnL) ? 
    (is_msb_flag[5] | is_msb_flag[6] | is_msb_flag[7] ? S_inside[3] : (is_msb_flag[4] ? ~S_inside[3] : (is_msb_flag[3] ? ~S_inside[3] : S_inside[3] ))) : S_inside[3];
        /* if is_msb_flag[7] is asserted then s[3] = s_inside[3] (do nothing) */
        /* if is_msb_flag[6] is asserted then s[3] = s_inside[3] (do nothing) */
        /* if is_msb_flag[5] is asserted then s[3] = s_inside[3] (do nothing) */
        /* if is_msb_flag[4] is asserted invert s3 directly */ 
        /* else check if is_msb_flag[3] is asserted */
    
    assign S[2] = (btnL) ? 
    (is_msb_flag[4] | is_msb_flag[5] | is_msb_flag[6] | is_msb_flag[7] ? S_inside[2] : (is_msb_flag[3] ? ~S_inside[2] : (is_msb_flag[2] ? ~S_inside[2] : S_inside[2] ))) : S_inside[2];
        /* if is_msb_flag[7] is asserted then s[2] = s_inside[2] (do nothing) */
        /* if is_msb_flag[6] is asserted then s[2] = s_inside[2] (do nothing) */
        /* if is_msb_flag[5] is asserted then s[2] = s_inside[2] (do nothing) */
        /* if is_msb_flag[4] is asserted then s[2] = s_inside[2] (do nothing) */
        /* if is_msb_flag[3] is asserted invert s2 directly */ 
        /* else check if is_msb_flag[2] is asserted */
    
    assign S[1] = (btnL) ? 
    (is_msb_flag[3] | is_msb_flag[4] | is_msb_flag[5] | is_msb_flag[6] | is_msb_flag[7] ? S_inside[1] : (is_msb_flag[2] ? ~S_inside[1] : (is_msb_flag[1] ? ~S_inside[1] : S_inside[1] ))) : S_inside[1];
        /* if is_msb_flag[7] is asserted then s[1] = s_inside[1] (do nothing) */
        /* if is_msb_flag[6] is asserted then s[1] = s_inside[1] (do nothing) */
        /* if is_msb_flag[5] is asserted then s[1] = s_inside[1] (do nothing) */
        /* if is_msb_flag[4] is asserted then s[1] = s_inside[1] (do nothing) */
        /* if is_msb_flag[3] is asserted then s[1] = s_inside[1] (do nothing) */
        /* if is_msb_flag[2] is asserted invert s1 directly */ 
        /* else check if is_msb_flag[1] is asserted */
         
     assign S[0] = (btnL) ? 
    (is_msb_flag[2] | is_msb_flag[3] | is_msb_flag[4] | is_msb_flag[5] | is_msb_flag[6] | is_msb_flag[7] ? S_inside[0] : (is_msb_flag[1] ? ~S_inside[0] : (is_msb_flag[0] ? ~S_inside[0] : S_inside[0] ))) : S_inside[0];
        /* if is_msb_flag[7] is asserted then s[0] = s_inside[0] (do nothing) */
        /* if is_msb_flag[6] is asserted then s[0] = s_inside[0] (do nothing) */
        /* if is_msb_flag[5] is asserted then s[0] = s_inside[0] (do nothing) */
        /* if is_msb_flag[4] is asserted then s[0] = s_inside[0] (do nothing) */
        /* if is_msb_flag[3] is asserted then s[0] = s_inside[0] (do nothing) */
        /* if is_msb_flag[2] is asserted then s[0] = s_inside[0] (do nothing) */
        /* if is_msb_flag[1] is asserted invert s1 directly */ 
        /* else check if is_msb_flag[0] is asserted */    
    
    assign led[15] = btnL;
    assign led[14] = btnL;
    
endmodule
