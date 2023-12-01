module ysyx_IDU (
  input [31:0] inst,
  input [31:0] pc,
  output wire rf_wr_en,
  output wire alu_a_sel,
  output wire rf_wr_sel,
  output wire do_jump,
  output wire is_ebreak,
  output wire[31:0] inst_imm
);

wire [6:0] op;
wire [2:0] funct;

// 列出指令类型
wire is_addi;
wire is_auipc;
wire is_lui;
wire is_jal;
wire is_jalr;
wire is_sw;
wire is_I;
wire is_U;
wire is_J;

// 解析指令
assign op = inst[6:0];
assign funct = inst[14:12];

//分析指令类型
assign  is_addi = (op == 7'h13) && (funct == 3'h0);
assign  is_auipc = (op == 7'h17);
assign  is_lui = (op == 7'h37);
assign  is_ebreak = (op == 7'h73);
assign  is_jal = (op == 7'h6f);
assign  is_jalr = (op == 7'h67) && (funct == 3'h0);
assign  is_sw = (op == 7'h23) && (funct == 3'h2);
assign  is_I = is_addi | is_jalr;
assign  is_U = is_auipc;
assign  is_J = is_jal;

// 扩展立即数
ysyx_ImmExtend imm0(
    .inst(inst),
    .imm(inst_imm)
);

// 处理寄存器写使能信号
assign rf_wr_en = is_I | is_U | is_J;

// 处理寄存器写选择信号
assign rf_wr_sel = is_J | is_jalr;

// 处理跳转信号
assign do_jump = is_J | is_jalr;

// 处理alu_a_sel
assign alu_a_sel = is_I;




endmodule

