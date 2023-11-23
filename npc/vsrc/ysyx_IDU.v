module ysyx_IDU (
  input [31:0] inst,
  output wire rf_wr_en,
  output wire is_ebreak,
  output wire[4:0] inst_rs1,
  output wire[4:0] inst_rd,
  output wire[31:0] inst_imm
);
wire [6:0] op;
wire [2:0] funct;
wire [11:0] imm;

// 列出指令类型
wire is_addi;
wire is_I;

// 解析指令
assign op = inst[6:0];
assign funct = inst[14:12];
assign inst_rd = inst[11:7];
assign inst_rs1 = inst[19:15];
assign imm = inst[31:20];

//分析指令类型
assign is_addi = (op == 7'h13) && (funct == 3'h0);
assign is_ebreak = (op == 7'h73);
assign is_I = is_addi;

// 扩展imm
assign inst_imm = {{20{imm[11]}}, imm[11:0]};

// 处理输出信号
assign rf_wr_en = is_I ? 1 : 0;


 

endmodule

