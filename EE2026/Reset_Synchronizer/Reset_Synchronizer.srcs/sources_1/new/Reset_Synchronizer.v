`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
module Reset_Synchronizer (
    input wire async_reset,        // Asynchronous reset signal
    input wire clk,                // Clock signal
    output sync_reset              // Synchronized reset signal
);

reg [1:0] sync_reset_reg = 2'b00;  // Register to synchronize the reset

always @(posedge clk or negedge async_reset) begin
    if (!async_reset) begin        // Active low configuration                 
                                   // Asynchronous reset assertion detected
        sync_reset_reg <= 2'b00;   // Synchronize to '1' for two cycles
    end else begin
                                   // Synchronize the reset signal
        sync_reset_reg <= {sync_reset_reg[0], async_reset}; // Shift and sample the reset
    end
end

assign sync_reset = sync_reset_reg[1]; // Output the synchronized reset signal

endmodule

// Code by JJ Ho
//reset synchronizer for 100MHz clk
//always@(posedge clk_100MHz or negedge asyncrst_n)
//begin
//	if(!asyncrst_n)
//		begin
//			{buf_100mhz, rff1} <= 2'b0; 			
//		end 
//	else
//		begin
//			{buf_100mhz, rff1} <= {rff1, 1'b1};		
//		end 
//end 