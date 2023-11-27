import "DPI-C" function void ebreak();

module ysyx_EXU (
  input clk,
  input rf_wr_en,
  input is_ebreak,
  input alu_a_sel,
  input rf_wr_sel,
  input [31:0] inst,
  input [31:0] pc,
  input [31:0] imm,
  output [31:0] jump_addr
);

wire [31:0] alu_a;
wire [31:0] alu_out;
wire [31:0] rf_wdata;
wire [31:0] rs1;

assign alu_a = alu_a_sel ? rs1 : pc;

assign rf_wdata = rf_wr_sel ? pc + 4 : alu_out;

assign jump_addr = alu_a_sel ? ({alu_out[31:1], 1'b0}) : alu_out;

always @(is_ebreak) begin
  if (is_ebreak) ebreak();
end

ysyx_ALU alu0(
  .SrcA (alu_a),
  .SrcB (imm),
  .func (4'b000),
  .ALUout (alu_out)
);

ysyx_RegisterFile regfile0(
  .clk (clk),
  .rf_wr_en (rf_wr_en),
  .waddr (inst[11:7]),
  .wdata (rf_wdata),
  .raddr (inst[19:15]),
  .rdata (rs1)
);
  
endmodule


