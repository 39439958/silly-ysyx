module ysyx_IDU (
  input [31:0] inst,
  input [31:0] pc,
  output wire rf_wr_en,
  output wire rf_wr_sel,
  output wire do_jump,
  output wire alu_a_sel,
  output wire alu_b_sel,
  output reg[3:0] alu_ctrl,
  output wire[31:0] imm
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
    wire is_ebreak;

    wire is_add_type;
    wire is_I;
    wire is_U;
    wire is_J;
    wire is_R;

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

    assign  is_add_type = is_addi | is_auipc | is_jal | is_jalr;
    assign  is_I = is_addi | is_jalr;
    assign  is_U = is_auipc;
    assign  is_J = is_jal;

    // 扩展立即数
    ysyx_ImmExtend imm0(
        .inst(inst),
        .imm(imm)
    );

    // rf_wr_en
    assign rf_wr_en = is_I | is_U | is_J;

    // rf_wr_sel
    assign rf_wr_sel = is_J | is_jalr;

    // do_jump
    assign do_jump = is_J | is_jalr;

    // alu_a_sel
    assign alu_a_sel = is_I | is_R;

    // alu_b_sel
    assign alu_b_sel = ~is_R;

    // alu_sel
    always@(*)
    begin
        if(is_add_type) alu_ctrl = 4'b0000;
        else if(is_lui) alu_ctrl = 4'b1110;
        else alu_ctrl = 0;
    end

    // is_ebreak
    import "DPI-C" function void ebreak();
    always @(is_ebreak) begin
        if (is_ebreak) ebreak();
    end

endmodule

