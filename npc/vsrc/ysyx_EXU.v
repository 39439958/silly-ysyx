import "DPI-C" function void ebreak();

module ysyx_EXU (
  input clk,
  input rf_wr_en,
  input is_ebreak,
  input [4:0] rs1,
  input [4:0] rd,
  input [31:0] imm
);

wire [31:0] alu_a;
wire [31:0] alu_out;

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
  .waddr (rd),
  .wdata (alu_out),
  .raddr (rs1),
  .rdata (alu_a)
);
  
endmodule


