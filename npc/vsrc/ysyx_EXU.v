module ysyx_EXU (
    input clk,
    input [31:0] inst,
    input [31:0] pc,
    input rf_wr_en,
    input [1:0] rf_wr_sel,
    input alu_a_sel,
    input alu_b_sel,
    input [3:0] alu_ctrl,
    input [31:0] imm,
    input [2:0] dm_rd_sel,
    input [1:0] dm_wr_sel,
    input [2:0] BrType,
    output BrE,
    output [31:0] jump_addr
);
    // alu
    wire [31:0] alu_a;
    wire [31:0] alu_b;
    wire [31:0] alu_out;
    assign  alu_a = alu_a_sel ? rs1 : pc;
    assign  alu_b = alu_b_sel ? imm : rs2;

    // regfile
    reg [31:0] rf_wdata;
    wire [31:0] rs1, rs2;
    always@(*)
    begin
        case(rf_wr_sel)
        2'b00:  rf_wdata = 32'h0;
        2'b01:  rf_wdata = pc + 4;
        2'b10:  rf_wdata = alu_out;
        2'b11:  rf_wdata = dm_data;
        default:  rf_wdata = 32'h0;
        endcase
    end
    assign jump_addr = alu_a_sel ? ({alu_out[31:1], 1'b0}) : alu_out;

    // // memory
    import "DPI-C" function void pmem_read(input int raddr, output int rdata);
    import "DPI-C" function void pmem_write(input int waddr, input int wdata, input byte wmask);
    reg [31:0] dm_data;
    always @(posedge clk) begin
        if (dm_wr_sel == 2'b01) begin
            pmem_write(alu_out, rs2, 8'b0000_0001);
            $display("%2h write in addr:%h", rs2[7:0], alu_out);
        end
        else if (dm_wr_sel == 2'b10) begin 
            pmem_write(alu_out, rs2, 8'b0000_0011);
            $display("%4h write in addr:%h", rs2[15:0], alu_out);
        end
        else if (dm_wr_sel == 2'b11) begin
            pmem_write(alu_out, rs2, 8'b0000_1111);
            $display("%8h write in addr:%h", rs2, alu_out);
        end
    end
    always @(posedge clk) begin 
        if (dm_rd_sel == 3'b001) begin
            pmem_read(alu_out, dm_data);
            dm_data = {{24{dm_data[7]}}, dm_data[7:0]};
            $display("read %2h in addr:%h", dm_data, alu_out);
        end
        else if (dm_rd_sel == 3'b010) begin
            pmem_read(alu_out, dm_data);
            dm_data = {{24{1'b0}}, dm_data[7 + (alu_out & 32'h3) * 8 :0 + (alu_out & 32'h3) * 8]};
            $display("read %2h in addr:%h", dm_data, alu_out);
        end
        else if (dm_rd_sel == 3'b011) begin 
            pmem_read(alu_out, dm_data);
            dm_data = {{16{dm_data[15]}}, dm_data[15:0]};
            $display("read %4h in addr:%h", dm_data, alu_out);
        end
        else if (dm_rd_sel == 3'b100) begin
            pmem_read(alu_out, dm_data);
            dm_data = {{16{1'b0}}, dm_data[15:0]};
            $display("read %4h in addr:%h", dm_data, alu_out);
        end
        else if (dm_rd_sel == 3'b101) begin
            pmem_read(alu_out, dm_data);
            $display("read %h in addr:%h", dm_data, alu_out);
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
    ysyx_branch branch0(
        .REG1 (rs1),
        .REG2 (rs2),
        .Type (BrType),
        .BrE (BrE)
    );
  
endmodule


