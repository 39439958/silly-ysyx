module ysyx_EXU (
    input clk,
    input [31:0] inst,
    input [31:0] pc,
    input rf_wr_en,
    input rf_wr_sel,
    input alu_a_sel,
    input alu_b_sel,
    input [3:0] alu_ctrl,
    input [31:0] imm,
    input [2:0] dm_rd_sel,
    input [1:0] dm_wr_sel,
    output [31:0] jump_addr
);
    // alu
    wire [31:0] alu_a;
    wire [31:0] alu_b;
    wire [31:0] alu_out;
    assign  alu_a = alu_a_sel ? rs1 : pc;
    assign  alu_b = alu_b_sel ? imm : rs2;

    // regfile
    wire [31:0] rf_wdata;
    wire [31:0] rs1, rs2;
    assign rf_wdata = rf_wr_sel ? pc + 4 : alu_out;
    assign jump_addr = alu_a_sel ? ({alu_out[31:1], 1'b0}) : alu_out;

    // // memory
    // import "DPI-C" function void pmem_read(input int raddr, output int rdata);
    import "DPI-C" function void pmem_write(input int waddr, input int wdata, input byte wmask);
    // wire [63:0] rdata;
    always @(*) begin
        if (dm_wr_sel == 2'b11) begin
            pmem_write(alu_out, rs2, 8'b0000_1111);
        end
    end

    ysyx_ALU alu0(
        .SrcA (alu_a),
        .SrcB (alu_b),
        .func (alu_ctrl),
        .ALUout (alu_out)
    );

    ysyx_RegisterFile regfile0(
        .clk (clk),
        .rf_wr_en (rf_wr_en),
        .waddr (inst[11:7]),
        .wdata (rf_wdata),
        .raddr1 (inst[19:15]),
        .raddr2 (inst[24:20]),
        .rdata1 (rs1),
        .rdata2 (rs2)
    );
  
endmodule


