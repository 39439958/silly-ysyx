module top (
  input wire clk,
  input wire rst,
  input wire [31:0] inst,
  output wire [31:0] pc,
);
wire [] inst_type;
wire [4:0] inst_rs1;
wire [4:0] inst_rs2;
wire [4:0] inst_rd;
wire [31:0] inst_imm;


ysyx_PC pc0(
  .clk (clk),
  .rst (rst),
  .pc (pc)
);
ysyx_IDU idu0(
  .inst (inst),
  .inst_type (inst_type),
  .inst_rs1 (inst_rs1),
  .inst_rs2 (inst_rs2)
  .inst_rd (inst_rd),
  .inst_imm (inst_imm)
);
ysyx_EXU(
  .clk (clk),
  .rs1 (rs1),
  .rd (rd),
  .imm (imm)
);
yxys_Reg(
  
)

endmodule