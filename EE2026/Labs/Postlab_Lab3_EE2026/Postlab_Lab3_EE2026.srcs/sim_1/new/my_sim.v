`timescale 1ns / 1ps

module my_sim(
    );
    reg clock_in;
    wire [1:0]LED;
    
    Postlab3_Top dut(clock_in, LED[1:0]);
    
    initial begin
          clock_in = 0;  
    end
    
    always begin
        #5 clock_in = ~clock_in; // 10ns per clock cycle = 100MHz
    end
endmodule
