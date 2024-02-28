`timescale 1ns / 1ps

module blinky(input clock, input btnC, input [2:0] sw, output [2:0]led);

    reg [26:0] count = 0;
    reg [26:0] count_1 = 0;
    reg [26:0] count_2 = 0;
    
    reg [2:0]led_status = 0;
    
    always @ (posedge clock)
    begin
        if(btnC==1)
            begin 
                count <= 0; 
                count_1 <= 0;
                count_2 <= 0; 
            end // using a switch to interrupt the counting
        else begin
            count <= count + 1;
            count_1 <= count_1 + 1;
            count_2 <= count_2 + 1;
            if(count>=49_999_999) 
            begin
                count <= 0;
                led_status[0] <= ~led_status[0];
            end
            if(count_1>=49_999_99) 
            begin
                count_1 <= 0;
                led_status[1] <= ~led_status[1];
            end
            if(count_2>=49_999_9) 
            begin
                count_2 <= 0;
                led_status[2] <= ~led_status[2];
            end
        end
    end
    
    assign led[0] = led_status[0] & sw[0];
    assign led[1] = led_status[1] & sw[1];
    assign led[2] = led_status[2] & sw[2];
    
endmodule
