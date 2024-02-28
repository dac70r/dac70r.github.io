`timescale 1ns / 1ps

module Postlab3_Top(input CLOCK, output reg [7:0]LED = 8'b0000_0000);
    
    reg [31:0] count = 0;
    reg [2:0] slow_count = 0;
    reg slow_clock = 0;
    
    always @ (posedge CLOCK)
    begin
        count <= count + 1;
        if(count==55_500_000)
        begin
            count <= 0;
            slow_clock <= ~slow_clock;
//            slow_count <= slow_count + 1;
        end
    end
    
    always @ (slow_clock)
    begin
        case(slow_count)
            0: LED[0] <= 8'b0000_0000;
            1: LED[1] <= 1;
            2: LED[2] <= 1;
            3: LED[3] <= 1;
            4: LED[4] <= 1;
            5: LED[5] <= 1;
            6: LED[6] <= 1;
            7: LED[7] <= 1;
        endcase
        slow_count <= slow_count + 1;
    end
endmodule
