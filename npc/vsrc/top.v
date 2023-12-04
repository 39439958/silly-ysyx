module top (
    input clk,
    input wire rst,
    input wire [31:0] inst,
    output wire [31:0] pc
);
    // idu
    wire rf_wr_en;
    wire rf_wr_sel;
    wire do_jump;
    wire alu_a_sel;
    wire alu_b_sel;
    wire [3:0] alu_ctrl;
    wire [31:0] imm;
    wire [2:0] dm_rd_sel;
    wire [1:0] dm_wr_sel;

    // exu
    wire [31:0] jump_addr;


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
        .rf_wr_sel (rf_wr_sel),
        .do_jump (do_jump),
        .alu_a_sel (alu_a_sel),
        .alu_b_sel (alu_b_sel), 
        .alu_ctrl (alu_ctrl),
        .dm_rd_sel (dm_rd_sel),
        .dm_wr_sel (dm_wr_sel),
        .imm (imm)
    );

    ysyx_EXU exu0(
        .clk (clk),
        .inst (inst),
        .pc (pc),
        .rf_wr_en (rf_wr_en),
        .rf_wr_sel (rf_wr_sel),
        .alu_a_sel (alu_a_sel),
        .alu_b_sel (alu_b_sel),
        .alu_ctrl (alu_ctrl),
        .imm (imm),
        .dm_rd_sel (dm_rd_sel),
        .dm_wr_sel (dm_wr_sel),
        .jump_addr (jump_addr)
    );

endmodule

