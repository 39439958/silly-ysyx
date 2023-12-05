module ysyx_branch(         
input[31:0]	REG1,
input[31:0] REG2,
input[2:0] Type,
output reg BrE
);
wire signed [31:0] signed_REG1;
wire signed [31:0] signed_REG2;

assign signed_REG1 = REG1;
assign signed_REG2 = REG2; 
always@(*)
begin
	case(Type)
        3'b010: BrE = (signed_REG1 == signed_REG2 ? 1 : 0);
        3'b011: BrE = (signed_REG1 != signed_REG2 ? 1 : 0);
        3'b100: BrE = (signed_REG1 < signed_REG2 ? 1 : 0);
        3'b101: BrE = (signed_REG1 >= signed_REG2 ? 1 : 0);
        3'b110: begin
            case({signed_REG1[31],signed_REG2[31]})
                2'b00: BrE = signed_REG1 < signed_REG2;
                2'b01: BrE = 1;
                2'b10: BrE = 0;
                2'b11: BrE = signed_REG1 < signed_REG2;
                default: BrE = 0;
            endcase
        	end
        3'b111: begin
        	case({signed_REG1[31],signed_REG2[31]})
                2'b00: BrE = signed_REG1 >= signed_REG2;
                2'b01: BrE = 0;
                2'b10: BrE = 1;
                2'b11: BrE = signed_REG1 >= signed_REG2;
                default: BrE = 0;
            endcase
        	end
        default: BrE = 0;
	endcase
end
endmodule