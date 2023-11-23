module ysyx_RegisterFile (
  input clk,
  input rf_wr_en,

  input [4:0] waddr,
  input [31:0] wdata,

  input [4:0] raddr,
  output [31:0] rdata
);
  
  reg [31:0] rf [31:0];
  
  always @(posedge clk) begin
    if (rf_wr_en) rf[waddr] <= wdata;
  end

  assign rdata = rf[raddr];
endmodule
