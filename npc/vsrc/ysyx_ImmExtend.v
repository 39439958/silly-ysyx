module ysyx_ImmExtend (
    input [31:0] inst,
    output [31:0] imm
);
    
    ysyx_MuxKey #(9, 7, 32) mux0 ( imm, inst[6:0], {
        7'b0010111, {inst[31:12], 12'b0}, // auipc
        7'b0110111, {inst[31:12], 12'b0}, // lui
        7'b0010011, {{20{inst[31]}}, inst[31:20]}, // addi srai xori andi srli slli
        7'b1101111, {{11{inst[31]}}, inst[31], inst[19:12], inst[20], inst[30:21], 1'b0}, // jal
        7'b1100111, {{20{inst[31]}}, inst[31:20]}, // jalr
        7'b0100011, {{20{inst[31]}}, inst[31:25], inst[11:7]}, // sw sh sb
        7'b0000011, {{20{inst[31]}}, inst[31:20]}, // lw lbu lb lh lhu
        7'b0010011, {{20{inst[31]}}, inst[31:20]}, // sltiu
        7'b1100011, {{19{inst[31]}}, inst[31], inst[7], inst[30:25], inst[11:8], 1'b0} // beq bne
    });
endmodule
