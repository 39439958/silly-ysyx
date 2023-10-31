module ysyx_IDU (
  input [31:0] inst,
  output wire[] inst_type,
  output wire[4:0] inst_rs1,
  output wire[4:0] inst_rs2,
  output wire[4:0] inst_rd,
  output wire[31:0] inst_imm
);
wire [6:0] op;
wire [2:0] funct;
wire [4:0] rs1;
wire [4:0] rs2;
wire [4:0] rd;
wire []

wire is_addi;

wire is_I;


assign op = inst[6:0];
assign funct = inst[14:12];

assign is_addi = (op == 7'h13) && (funct == 3'h0);

assign is_I = is_addi;





 

endmodule