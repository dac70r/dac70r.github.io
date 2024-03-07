`timescale 1ns / 1ps

module counter_3_secs(input main_clock, input master_switch, output reg led = 0);

reg [2:0]counter = 3'b000;
reg output_led = 0;

always @ (posedge main_clock)
begin
    if(master_switch)
        begin       
        if(counter==3)
            begin
                led <= 1;
                counter <= 0;
            end 
            counter <= counter + 1;
        end
    else
        begin counter <= 0; led <=0; end
end
endmodule
