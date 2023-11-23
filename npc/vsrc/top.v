module top (
  input clk,
  input wire rst,
  input wire [31:0] inst,
  output wire [31:0] pc
);
wire rf_wr_en;
wire is_ebreak;
wire [4:0] inst_rs1;
wire [4:0] inst_rd;
wire [31:0] inst_imm;


ysyx_PC pc0(
  .clk (clk),
  .rst (rst),
  .pc (pc)
);
ysyx_IDU idu0(
  .inst (inst),
  .rf_wr_en (rf_wr_en),
  .is_ebreak (is_ebreak),
  .inst_rs1 (inst_rs1),
  .inst_rd (inst_rd),
  .inst_imm (inst_imm)
);
ysyx_EXU exu0(
  .clk (clk),
  .rf_wr_en (rf_wr_en),
  .is_ebreak (is_ebreak),
  .rs1 (inst_rs1),
  .rd (inst_rd),
  .imm (inst_imm)
);


endmodule

