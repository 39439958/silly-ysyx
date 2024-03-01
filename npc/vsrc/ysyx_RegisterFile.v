module ysyx_RegisterFile (
    input clk,
    input [31:0] pc,

    input rf_wr_en,
    input [4:0] waddr,
    input [31:0] wdata,
    input [4:0] raddr1, raddr2,
    output [31:0] rdata1, rdata2,

    input csr_wr_en,
    input [11:0] csraddr,
    input reg [31:0] csrwdata,
    output reg[31:0] csrrdata,
    output reg[31:0] mtvecdata,
    input is_ecall,

    input is_mret,
    output reg[31:0] mepcdata
);
    reg [31:0] rf [31:0];
    reg [31:0] mstatus;
    reg [31:0] mtvec;
    reg [31:0] mepc;
    reg [31:0] mcause;

    always @(posedge clk) begin
        if (rf_wr_en) begin
            rf[waddr] <= wdata;
            //$display("waddr = %h, wdata = %h", waddr, wdata);
        end

        if (csr_wr_en) begin
          case(csraddr)
            12'h300: begin
              csrrdata = mstatus;
              mstatus = csrwdata;
            end
            12'h305: begin
              csrrdata = mtvec;
              mtvec = csrwdata;
            end
            12'h341: begin
              csrrdata = mepc;
              mepc = csrwdata;
            end
            12'h342: begin
              csrrdata = mcause;
              mcause = csrwdata;
            end
            default: begin
            end
          endcase
        end

        if (is_ecall) begin
          mtvecdata = mtvec;
          mcause = rf[5'd17];
          mepc = pc;
        end

        if (is_mret) begin
          mepcdata = mepc;
        end
    end
    
    assign rdata1 = rf[raddr1];
    assign rdata2 = rf[raddr2];    

endmodule
