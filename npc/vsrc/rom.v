module rom(
	input	[7:0] addr,
	output	[7:0]	q
);
    reg [7:0]mem[255:0];
	initial begin
        mem[8'h1c] = 8'h61;
        mem[8'h1b] = 8'h62;
        mem[8'h21] = 8'h63;
        mem[8'h23] = 8'h64;
        mem[8'h24] = 8'h65;
        mem[8'h2b] = 8'h66;
        mem[8'h34] = 8'h67;
        mem[8'h33] = 8'h68;
        mem[8'h43] = 8'h69;
        mem[8'h3b] = 8'h6a;
        mem[8'h42] = 8'h6b;
        mem[8'h4b] = 8'h6c;
        mem[8'h3a] = 8'h6d;
        mem[8'h31] = 8'h6e;
        mem[8'h44] = 8'h6f;
        mem[8'h4d] = 8'h70;
        mem[8'h15] = 8'h71;
        mem[8'h2d] = 8'h72;
        mem[8'h1b] = 8'h73;
        mem[8'h2c] = 8'h74;
        mem[8'h3c] = 8'h75;
        mem[8'h2a] = 8'h76;
        mem[8'h1d] = 8'h77;
        mem[8'h22] = 8'h78;
        mem[8'h35] = 8'h79;
        mem[8'h1a] = 8'h7a;
        mem[8'h29] = 8'h20;
        mem[8'h0e] = 8'h60;
        mem[8'h16] = 8'h31;
        mem[8'h1e] = 8'h32;
        mem[8'h26] = 8'h33;
        mem[8'h25] = 8'h34;
        mem[8'h2e] = 8'h35;
        mem[8'h36] = 8'h36;
        mem[8'h3d] = 8'h37;
        mem[8'h3e] = 8'h38;
        mem[8'h46] = 8'h39;
        mem[8'h45] = 8'h30;
        mem[8'h4e] = 8'h2d;
        mem[8'h55] = 8'h3d;
	end
	assign q = mem[addr];
endmodule
