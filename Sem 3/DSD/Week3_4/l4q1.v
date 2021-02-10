module mux8to1(d, sel, f);
input [0:7]d;
input [2:0] sel;
output f;
reg f;
always@(sel)
begin
case(sel)
3'b000: f=d[0];
3'b001: f=d[1];
3'b010: f=d[2];
3'b011: f=d[3];
3'b100: f=d[4];
3'b101: f=d[5];
3'b110: f=d[6];
3'b111: f=d[7];
endcase
end
endmodule

module l4q1(bcd, exc);
input [3:0]bcd;
output [3:0]exc;

mux8to1 stage0({1'b0,1'b0,bcd[0],1'b1,1'b1,X,X,X}, bcd[3:1], exc[3]);
mux8to1 stage1({bcd[0],1'b1,~bcd[0],1'b0,bcd[0],X,X,X}, bcd[3:1], exc[2]);
mux8to1 stage2({~bcd[0],bcd[0],~bcd[0],bcd[0],~bcd[0],X,X,X}, bcd[3:1], exc[1]);
assign exc[0]=~bcd[0];
endmodule

