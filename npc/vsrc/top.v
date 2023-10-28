module top (
    input clk,
    input rst,
    input ps2_clk,
    input ps2_data,
    output [6:0] seg0,
    output [6:0] seg1,
    output [6:0] seg4,
    output [6:0] seg5,
    output [6:0] seg2,
    output [6:0] seg3
);

reg [7:0] ps2_output;
reg [7:0] ascii_out;

ps2_keyboard my_keyboard(
    .clk(clk),
    .resetn(~rst),
    .ps2_clk(ps2_clk),
    .ps2_data(ps2_data),
    .ps2_output(ps2_output)
);

seg my_seg(
    .clk(clk),
    .rst(rst),
    .in(ps2_output),
    .in2(ascii_out),
    .h1(seg0),
    .h2(seg1),
    .h3(seg4),
    .h4(seg5),
    .h5(seg2),
    .h6(seg3)
);

rom my_rom(
    .addr(ps2_output),
    .q(ascii_out)
);

endmodule
