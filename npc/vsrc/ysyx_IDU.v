module ysyx_IDU (
  input [31:0] inst,
  input [31:0] pc,
  output wire rf_wr_en,
  output reg[1:0] rf_wr_sel,
  output wire do_jump,
  output reg[2:0] BrType,
  output wire alu_a_sel,
  output wire alu_b_sel,
  output reg[3:0] alu_ctrl,
  output reg[2:0] dm_rd_sel,
  output reg[1:0] dm_wr_sel,
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
    wire is_sltiu;

    wire  is_beq;
    wire  is_bne;
    wire  is_blt;
    wire  is_bge;
    wire  is_bltu;
    wire  is_bgeu;

    wire is_lb;
    wire is_lbu;
    wire is_lh;
    wire is_lhu;
    wire is_lw;

    wire is_sb;
    wire is_sh;
    wire is_sw;

    wire is_add_type;
    wire is_I;
    wire is_U;
    wire is_J;
    wire is_R;
    wire is_S;
    wire is_B;

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
    assign  is_lw = (op == 7'h3) && (funct == 3'h2);
    assign  is_sltiu = (op == 7'h13) && (funct == 3'h3);

    assign  is_beq  = (op == 7'h63) && (funct ==3'h0);
    assign  is_bne  = (op == 7'h63) && (funct ==3'h1);
    assign  is_blt  = (op == 7'h63) && (funct ==3'h4);
    assign  is_bge  = (op == 7'h63) && (funct ==3'h5);
    assign  is_bltu = (op == 7'h63) && (funct ==3'h6);
    assign  is_bgeu = (op == 7'h63) && (funct ==3'h7);

    assign  is_add_type = is_addi | is_auipc | is_jal | is_jalr | is_S | is_lw | is_B;
    assign  is_I = is_addi | is_jalr | is_lw | is_sltiu;
    assign  is_U = is_auipc | is_lui;
    assign  is_J = is_jal;
    assign  is_S = is_sw | is_sb | is_sh;
    assign  is_B = is_beq | is_bne | is_blt | is_bge | is_bltu | is_bgeu;
    

    // 扩展立即数
    ysyx_ImmExtend imm0(
        .inst(inst),
        .imm(imm)
    );

    // rf_wr_en
    assign rf_wr_en = is_I | is_U | is_J;
    
    // rf_wr_sel
    always@(*)
    begin
        if(is_jal | is_jalr) rf_wr_sel = 2'b01;
        else if(is_U | is_addi | is_sltiu) rf_wr_sel = 2'b10;
        else if(is_lb | is_lh | is_lw | is_lbu | is_lhu) rf_wr_sel = 2'b11;
        else rf_wr_sel = 2'b00;
    end 

    // do_jump
    assign do_jump = is_J | is_jalr;

    //[2:0]BrType
    always@(*)
    begin
        if(is_beq) BrType = 3'b010;
        else if(is_bne) BrType = 3'b011;
        else if(is_blt) BrType = 3'b100;
        else if(is_bge) BrType = 3'b101;
        else if(is_bltu) BrType = 3'b110;
        else if(is_bgeu) BrType = 3'b111;
        else BrType = 0;
    end

    // alu_a_sel
    assign alu_a_sel = is_I | is_R | is_S;

    // alu_b_sel
    assign alu_b_sel = ~is_R;

    // alu_sel
    always@(*)
    begin
        if(is_add_type) alu_ctrl = 4'b0000;
        else if(is_lui) alu_ctrl = 4'b1110;
        else if(is_sltiu) alu_ctrl = 4'b0011;
        else alu_ctrl = 0;
    end

    // dm_rd_sel
    always@(*)
    begin
        if(is_lb) dm_rd_sel = 3'b001;
        else if(is_lbu) dm_rd_sel = 3'b010;
        else if(is_lh) dm_rd_sel = 3'b011;
        else if(is_lhu) dm_rd_sel = 3'b100;
        else if(is_lw) dm_rd_sel = 3'b101;
        else dm_rd_sel = 3'b000;
    end

    // dm_wr_sel
    always@(*)
    begin
        if(is_sb) dm_wr_sel = 2'b01;
        else if(is_sh) dm_wr_sel = 2'b10;
        else if(is_sw) dm_wr_sel = 2'b11;
        else dm_wr_sel = 2'b00;
    end  

    // is_ebreak
    import "DPI-C" function void ebreak();
    always @(is_ebreak) begin
        if (is_ebreak) ebreak();
    end

endmodule

