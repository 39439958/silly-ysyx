module ysyx_PC (
  input clk,
  input rst,
  input jump,
  input [31:0] jump_addr,
  output reg [31:0] pc
);
  
  always@(posedge clk)
  begin
      if(rst) pc <= 32'h80000000;
      else if(jump) pc <= jump_addr;
      else pc <= pc + 4;
  end

endmodule

