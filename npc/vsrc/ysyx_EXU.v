module ysyx_EXU (
    input clk,
    input [31:0] inst,
    input [31:0] pc,
    input rf_wr_en,
    input csr_wr_en,
    input [2:0] rf_wr_sel,
    input alu_a_sel,
    input alu_b_sel,
    input [3:0] alu_ctrl,
    input [31:0] imm,
    input [2:0] dm_rd_sel,
    input [1:0] dm_wr_sel,
    input [2:0] BrType,
    output BrE,
    output [31:0] jump_addr,
    input is_ecall,
    output reg[31:0] mtvecdata,
    input is_mret,
    output reg[31:0] mepcdata
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
    wire [31:0] csr;
    wire [31:0] csrwdata;
    assign csrwdata = (inst[14:12] == 3'b010 ? (csr | rs1) : rs1);
    always@(*)
    begin
        case(rf_wr_sel)
        3'b000:  rf_wdata = 32'h0;
        3'b001:  rf_wdata = pc + 4;
        3'b010:  rf_wdata = alu_out;
        3'b011:  rf_wdata = dm_data;
        3'b100:  rf_wdata = csr;
        default:  rf_wdata = 32'h0;
        endcase
    end
    assign jump_addr = alu_a_sel ? ({alu_out[31:1], 1'b0}) : alu_out;

    // memory
    import "DPI-C" function void pmem_read(input int raddr, output int rdata);
    import "DPI-C" function void pmem_write(input int waddr, input int wdata, input byte wmask);
    reg [31:0] dm_data;
    // write memory
    always @(posedge clk) begin
        if (dm_wr_sel == 2'b01) begin
            pmem_write(alu_out, rs2, 8'b0000_0001);
           // $display("%2h write in addr:%h", rs2[7:0], alu_out);
        end
        else if (dm_wr_sel == 2'b10) begin 
            pmem_write(alu_out, rs2, 8'b0000_0011);
            // $display("%4h write in addr:%h", rs2[15:0], alu_out);
        end
        else if (dm_wr_sel == 2'b11) begin
            pmem_write(alu_out, rs2, 8'b0000_1111);
            // $display("%8h write in addr:%h", rs2, alu_out);
        end
    end
    // read memory
    always @(posedge clk) begin 
      // lb
        if (dm_rd_sel == 3'b001) begin
            pmem_read(alu_out, dm_data);
            if (alu_out[1:0] == 2'b00) 
                dm_data = {{24{dm_data[7]}}, dm_data[7:0]};
            else if (alu_out[1:0] == 2'b01)
                dm_data = {{24{dm_data[15]}}, dm_data[15:8]};
            else if (alu_out[1:0] == 2'b10)
                dm_data = {{24{dm_data[23]}}, dm_data[23:16]};
            else
                dm_data = {{24{dm_data[31]}}, dm_data[31:24]};
            // $display("read %2h in addr:%h", dm_data, alu_out);
        end
      // lbu
        else if (dm_rd_sel == 3'b010) begin
            pmem_read(alu_out, dm_data);
            if (alu_out[1:0] == 2'b00) 
                dm_data = {{24{1'b0}}, dm_data[7:0]};
            else if (alu_out[1:0] == 2'b01)
                dm_data = {{24{1'b0}}, dm_data[15:8]};
            else if (alu_out[1:0] == 2'b10)
                dm_data = {{24{1'b0}}, dm_data[23:16]};
            else
                dm_data = {{24{1'b0}}, dm_data[31:24]};
            // $display("read %2h in addr:%h", dm_data, alu_out);
        end
      // lh
        else if (dm_rd_sel == 3'b011) begin 
            pmem_read(alu_out, dm_data);
            if (alu_out[1:0] == 2'b00) 
                dm_data = {{16{dm_data[15]}}, dm_data[15:0]};
            else if (alu_out[1:0] == 2'b01)
                dm_data = {{16{dm_data[23]}}, dm_data[23:8]};
            else if (alu_out[1:0] == 2'b10)
                dm_data = {{16{dm_data[31]}}, dm_data[31:16]};
            else
                dm_data = {{24{dm_data[31]}}, dm_data[31:24]};
            // $display("read %4h in addr:%h", dm_data, alu_out);
        end
      // lhu
        else if (dm_rd_sel == 3'b100) begin
            pmem_read(alu_out, dm_data);
            if (alu_out[1:0] == 2'b00) 
                dm_data = {{16{1'b0}}, dm_data[15:0]};
            else if (alu_out[1:0] == 2'b01)
                dm_data = {{16{1'b0}}, dm_data[23:8]};
            else if (alu_out[1:0] == 2'b10)
                dm_data = {{16{1'b0}}, dm_data[31:16]};
            else
                dm_data = {{24{1'b0}}, dm_data[31:24]};
            // $display("read %4h in addr:%h", dm_data, alu_out);
        end
      // lw
        else if (dm_rd_sel == 3'b101) begin
            pmem_read(alu_out, dm_data);
            // $display("read %h in addr:%h", dm_data, alu_out);
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
        .pc (pc),
        .rf_wr_en (rf_wr_en),
        .waddr (inst[11:7]),
        .wdata (rf_wdata),
        .raddr1 (inst[19:15]),
        .raddr2 (inst[24:20]),
        .rdata1 (rs1),
        .rdata2 (rs2),
        .csr_wr_en (csr_wr_en),
        .csraddr (inst[31:20]),
        .csrwdata (csrwdata),
        .csrrdata (csr),
        .is_ecall (is_ecall),
        .mtvecdata (mtvecdata),
        .is_mret (is_mret),
        .mepcdata (mepcdata)
    );
    ysyx_branch branch0(
        .REG1 (rs1),
        .REG2 (rs2),
        .Type (BrType),
        .BrE (BrE)
    );
  
endmodule


