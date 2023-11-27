module top (
  input clk,
  input wire rst,
  input wire [31:0] inst,
  output wire [31:0] pc
);
wire [31:0] jump_addr;

wire rf_wr_en;
wire alu_a_sel;
wire is_ebreak;
wire [31:0] inst_imm;

wire do_jump;
wire rf_wr_sel;

ysyx_PC pc0(
  .clk (clk),
  .rst (rst),
  .jump (do_jump),
  .jump_addr (jump_addr),
  .pc (pc)
);

ysyx_IDU idu0(
  .inst (inst),
  .pc (pc),
  .rf_wr_en (rf_wr_en),
  .alu_a_sel (alu_a_sel),
  .is_ebreak (is_ebreak),
  .rf_wr_sel (rf_wr_sel),
  .do_jump (do_jump),
  .inst_imm (inst_imm)
);

ysyx_EXU exu0(
  .clk (clk),
  .rf_wr_en (rf_wr_en),
  .rf_wr_sel (rf_wr_sel),
  .is_ebreak (is_ebreak),
  .alu_a_sel (alu_a_sel),
  .inst (inst),
  .pc (pc),
  .imm (inst_imm),
  .jump_addr (jump_addr)
);


endmodule

