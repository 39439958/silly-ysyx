module top (
    input clk,
    input wire rst
);
    // pc
    import "DPI-C" function void pmem_read(input int raddr, output int rdata, input byte rmask);
    wire [31:0] inst;
    wire [31:0] pc;
    wire jump;
    always @(posedge clk) begin
        if(~rst) pmem_read(pc, inst, 8'b0000_1111);
    end
    assign jump = BrE | do_jump;

    // idu
    wire rf_wr_en;
    wire csr_wr_en;
    wire [2:0] rf_wr_sel;
    wire do_jump;
    wire [2:0] BrType;
    wire alu_a_sel;
    wire alu_b_sel;
    wire [3:0] alu_ctrl;
    wire [31:0] imm;
    wire [2:0] dm_rd_sel;
    wire [1:0] dm_wr_sel;
    wire is_ecall;
    wire is_mret;

    // exu
    wire [31:0] jump_addr;
    wire BrE;
    wire [31:0] mtvecdata;
    wire [31:0] mepcdata;

    ysyx_PC pc0(
        .clk (clk),
        .rst (rst),
        .jump (jump),
        .jump_addr (jump_addr),
        .is_ecall (is_ecall),
        .mtvecdata (mtvecdata),
        .is_mret (is_mret),
        .mepcdata (mepcdata),
        .pc (pc)
    );

    ysyx_IDU idu0(
        .inst (inst),
        .pc (pc),
        .rf_wr_en (rf_wr_en),
        .rf_wr_sel (rf_wr_sel),
        .is_ecall (is_ecall),
        .is_mret (is_mret),
        .csr_wr_en (csr_wr_en),
        .do_jump (do_jump),
        .BrType (BrType),
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
        .csr_wr_en (csr_wr_en),
        .rf_wr_sel (rf_wr_sel),
        .alu_a_sel (alu_a_sel),
        .alu_b_sel (alu_b_sel),
        .alu_ctrl (alu_ctrl),
        .imm (imm),
        .dm_rd_sel (dm_rd_sel),
        .dm_wr_sel (dm_wr_sel),
        .BrType (BrType),
        .BrE (BrE),
        .jump_addr (jump_addr),
        .is_ecall (is_ecall),
        .mtvecdata (mtvecdata),
        .is_mret (is_mret),
        .mepcdata (mepcdata)
    );

endmodule

