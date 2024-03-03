`timescale 1ns / 1ps

module Postlab3_Top(input CLOCK, input switch, input btnR, input btnU, input btnL, input btnC, input [2:0] sw, output reg [6:0]seg=7'b111_1111, output reg dp = 1'b1, output reg [3:0]an=4'b1111,
                    output reg unlocked_led = 1'b0, output reg [8:0]LED=9'b0_0000_0000);
    
    reg [31:0] count_100_111hz = 0; // counter for the 100/111 hz clock
    
    reg [3:0] count_subtaskA = 0;   // counter for subtaskA
    reg subtaskA_done_flag = 0;     // raised when max_led is lit up
    
    // Wire instatiations
    wire clock_1hz_status;          // 1hz clock
    wire clock_10hz_status;         // 10hz clock
    wire clock_100hz_status;        // 100hz clock
    wire led_output_btnC;           // output pulse from the debouncing module
    wire led_output_btnL;           // output pulse from the debouncing module
    wire led_output_btnU;           // output pulse from the debouncing module
    wire led_output_btnR;           // output pulse from the debouncing module
    
    /* Subtask B Declarations */
    // Characters to appear in a sequence in order on 7-segment display
    //reg status_led = 0;             // the led for testing subtask B
    reg [1:0] segment_count = 2'b00;    // counter that keeps track what is current 'step'  
    reg [1:0] segment_count_L = 2'b00;      
    reg [1:0] segment_count_U = 2'b00;   
    reg [1:0] segment_count_R = 2'b00;   
    
    // Clock instatiations
    clk_1hz clk0 (CLOCK, clock_1hz_status);     // 1hz clock inst.
    clk_10hz clk1 (CLOCK, clock_10hz_status);   // 10hz clock inst.
    clk_100hz clk2 (CLOCK, clock_100hz_status); // 100hz clock inst. 
    
    // Debouncing circuit instatiation
    debouncing_Postlab3 db0 (CLOCK, btnC, led_output_btnC);
    debouncing_Postlab3 db1 (CLOCK, btnL, led_output_btnL);
    debouncing_Postlab3 db2 (CLOCK, btnU, led_output_btnU);
    debouncing_Postlab3 db3 (CLOCK, btnR, led_output_btnR);
    
    /* The Main Clock of the Module */
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
                begin count_subtaskA <= 9; end
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
                9: begin LED <= 9'b1_1111_1111; subtaskA_done_flag <= 1; end //
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

always @ (posedge led_output_btnC)
begin
    if(segment_count == 0)
    begin
        segment_count <= segment_count + 1; 
    end
    else if (segment_count == 1 & segment_count_L == 1 & segment_count_U == 1 & segment_count_R == 1)
    begin segment_count <= segment_count + 1; end
end

always @ (posedge led_output_btnL)
begin
    if(segment_count == 1 & segment_count_L == 0)
    begin
        segment_count_L <= segment_count_L + 1; 
    end
    else if(segment_count == 2 & segment_count_L == 1 & segment_count_U == 1 & segment_count_R == 1)
    begin segment_count_L <= segment_count_L + 1; end
end

always @ (posedge led_output_btnU)
begin
    if(segment_count == 1 & segment_count_L == 1 & segment_count_U == 0)
    begin
        segment_count_U <= segment_count_U + 1; 
    end
end

always @ (posedge led_output_btnR)
begin
    if(segment_count == 1 & segment_count_L == 1 & segment_count_U == 1 & segment_count_R == 0)
    begin
        segment_count_R <= segment_count_R + 1; 
    end
end

always @ (switch or unlocked_led or segment_count or segment_count_L or segment_count_U or segment_count_R) begin
if(subtaskA_done_flag)
    begin
        if(segment_count == 0 & segment_count_L == 0 & segment_count_U == 0 & segment_count_R == 0 )
            begin an <= 4'b1110; seg <= 7'b010_0111; end // c
        else if(segment_count == 1 & segment_count_L == 0 & segment_count_U == 0 & segment_count_R == 0)
            begin an <= 4'b1101; seg <= 7'b100_1111; end // l 
        else if(segment_count == 1 & segment_count_L == 1 & segment_count_U == 0 & segment_count_R == 0)
            begin an <= 4'b1011; seg <= 7'b110_0011; end // u
        else if(segment_count == 1 & segment_count_L == 1 & segment_count_U == 1 & segment_count_R == 0)
            begin an <= 4'b0111; seg <= 7'b010_1111; end // r
        else if(segment_count == 1 & segment_count_L == 1 & segment_count_U == 1 & segment_count_R == 1)
            begin an <= 4'b1110; seg <= 7'b010_0111; end // c
        else if(segment_count == 2 & segment_count_L == 1 & segment_count_U == 1 & segment_count_R == 1)
            begin an <= 4'b1101; seg <= 7'b100_1111; end // l 
        else if(segment_count == 2 & segment_count_L == 2 & segment_count_U == 1 & segment_count_R == 1)
            begin an <= 4'b1110; seg <= 7'b010_0111; unlocked_led <= 1; end // c
//        case(segment_count)
//            0: begin an <= 4'b1110; seg <= 7'b010_0111; end // c
//            1: begin an <= 4'b1101; seg <= 7'b100_1111; end // l 
//            2: begin an <= 4'b1011; seg <= 7'b110_0011; end // u
//            3: begin an <= 4'b0111; seg <= 7'b010_1111; end // r
//            4: begin an <= 4'b1110; seg <= 7'b010_0111; end // c
//            5: begin an <= 4'b1101; seg <= 7'b100_1111; end // l
//            6: begin an <= 4'b1110; seg <= 7'b010_0111; end // c
//            default: begin an <= 4'b1110; seg <= 7'b010_0111; unlocked_led <= 1; end
//        endcase
    end
end
endmodule
