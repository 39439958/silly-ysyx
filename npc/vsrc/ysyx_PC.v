module ysyx_PC (
  input clk,
  input rst,
  input jump,
  input [31:0] jump_addr,
  output reg [31:0] pc
);
  wire [31:0] pc_next;
  assign pc_next = pc + 32'h4;

  always@(posedge clk or posedge rst)
  begin
      if(rst) pc <= 32'h80000000;
      else if(jump) pc <= jump_addr;
      else pc <= pc_next;
  end

endmodule

