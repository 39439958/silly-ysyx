module ysyx_PC (
    input clk,
    input rst,
    input jump,
    input [31:0] jump_addr,
    input is_ecall,
    input [31:0] mtvecdata,
    input is_mret,
    input [31:0] mepcdata,
    output reg [31:0] pc
);

    always@(posedge clk)
    begin
        if(rst) pc <= 32'h80000000;
        else if(jump) pc <= jump_addr;
        else if(is_ecall) pc <= mtvecdata;
        else if(is_mret) pc <= mepcdata;
        else pc <= pc + 4;
    end

endmodule

