`timescale 1ns / 1ps

module Postlab3_Top(input CLOCK, input btnC, input [2:0] sw, output led, output reg [8:0]LED=9'b0_0000_0000);
    
    reg [31:0] count_100_111hz = 0; // counter for the 100/111 hz clock
    
    reg [3:0] count_subtaskA = 0;   // counter for subtaskA
    reg subtaskA_done_flag = 0;     // raised when max_led is lit up
    
    wire clock_1hz_status;          // 1hz clock
    wire clock_10hz_status;         // 10hz clock
    wire clock_100hz_status;        // 100hz clock
    
    clk_1hz clk0 (CLOCK, clock_1hz_status);     // 1hz clock inst.
    clk_10hz clk1 (CLOCK, clock_10hz_status);   // 10hz clock inst.
    clk_100hz clk2 (CLOCK, clock_100hz_status); // 100hz clock inst. 
    clk_4hz clk3 (CLOCK, led); // instantiate clock divider module 
    
    always @ (posedge CLOCK)
    begin
    // Increment the 100/111hz counter 
        count_100_111hz <= count_100_111hz + 1;     // 1.11s per cycle 
        
     // Increment the count_subtaskA, raise the subtaskA_done_flag when count_subtaskA == 9
        if(count_100_111hz == 110999999)                    // 1.11s per cycle (55_500_000 * 2 -1)
        begin
            count_100_111hz <= 0;
            count_subtaskA <= count_subtaskA + 1;
            if(count_subtaskA >= 9)
            begin subtaskA_done_flag <= 1; count_subtaskA <= 9; end
        end
    end
    
    /* Subtask A Execution - LED[0] to LED[7] light up gradually */
    // For every increment of count_subtaskA, light up a subsequent LED
    always @ (count_subtaskA)
    begin
    if(subtaskA_done_flag == 0)
        begin
            case(count_subtaskA)
                0: LED <= 9'b0_0000_0000;
                1: LED <= 9'b0_0000_0001;
                2: LED <= 9'b0_0000_0011;
                3: LED <= 9'b0_0000_0111;
                4: LED <= 9'b0_0000_1111;
                5: LED <= 9'b0_0001_1111;
                6: LED <= 9'b0_0011_1111;
                7: LED <= 9'b0_0111_1111;
                8: LED <= 9'b0_1111_1111;
                9: LED <= 9'b1_1111_1111;
                default: LED <= 9'b1_1111_1111;
            endcase
        end
        else
            begin
                if(sw[2]==1)
                    begin LED[8:3]<= 6'b1111_11; LED[2] <= clock_100hz_status; LED[1:0] <= 2'b11; end
                else if (sw[1]==1)
                    begin LED[8:2]<= 7'b1111_111; LED[1] <= clock_10hz_status; LED[0] <= 1'b1;end
                else if (sw[0]==1)
                    begin LED[8:1]<= 8'b1111_1111; LED[0] <= clock_1hz_status; end
                else
                    begin LED <= 9'b1_1111_1111; end
            end
    end
    
//wire clk_out;       // output from clk divider - 4hz clock freq
//reg on_off;         // register for storing on/off status

wire output_Q1; 
wire output_Q1_bar;
wire output_Q2; 
wire output_Q2_bar;



//dff dff1(clk_out, btnC, output_Q1, output_Q1_bar);
//dff dff2(clk_out, output_Q1, output_Q2, output_Q2_bar);

//assign led = output_Q1 & output_Q2_bar; 
    
endmodule
