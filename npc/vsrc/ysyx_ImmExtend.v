module ysyx_ImmExtend (
    input [31:0] inst,
    output [31:0] imm
);
    
    ysyx_MuxKey #(5, 7, 32) mux0 ( imm, inst[6:0], {
        7'b0010111, {inst[31:12], 12'b0},
        7'b0110111, {inst[31:12], 12'b0},
        7'b0010011, {{20{inst[31]}}, inst[31:20]},
        7'b1101111, {{11{inst[31]}}, inst[31], inst[19:12], inst[20], inst[30:21], 1'b0},
        7'b1100111, {{20{inst[31]}}, inst[31:20]}
    });
endmodule
