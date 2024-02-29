`timescale 1ns / 1ps

module Postlab3_Top(input CLOCK, output [1:0]LED);
    //= 8'b0000_0000
    reg [31:0] count = 0;
    reg [31:0] count_one = 0;
    reg [2:0] slow_count = 0;
    
    reg slow_clock = 0;
    reg slow_clock_one = 0;
    
    always @ (posedge CLOCK)
    begin
        count <= count + 1;
        if(count==55_500_000)
        begin
            count <= 0;
            slow_clock <= ~slow_clock;
            slow_count <= slow_count + 1;
        end
    end
    
    always @ (posedge CLOCK)
    begin
        count_one <= count_one + 1;
        if(count==49_999_999)
        begin
            count_one <= 0;
            slow_clock_one <= ~slow_clock_one;
        end
    end
    
    assign LED[0] = slow_clock;
    assign LED[1] = slow_clock_one;
    
//    always @ (slow_clock)
//    begin
//        case(slow_count-1)
//            0: LED[0] <= 1;
//            1: LED[1] <= 1;
//            2: LED[2] <= 1;
//            3: LED[3] <= 1;
//            4: LED[4] <= 1;
//            5: LED[5] <= 1;
//            6: LED[6] <= 1;
//            7: LED[7] <= 1;
//        endcase
//    end
endmodule
