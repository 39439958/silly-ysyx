module ysyx_RegisterFile (
    input clk,
    input rf_wr_en,
    input [4:0] waddr,
    input [31:0] wdata,
    input [4:0] raddr1, raddr2,
    output [31:0] rdata1, rdata2
);
  
    reg [31:0] rf [31:0];

    always @(posedge clk) begin
        if (rf_wr_en) begin
            rf[waddr] <= wdata;
            $display("China NO1! %d %d", rf[waddr], wdata);
        end
    end
    
    assign rdata1 = rf[raddr1];
    assign rdata2 = rf[raddr2];    

endmodule
