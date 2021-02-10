module mux2to1(w0, w1, s, f);
input w0, w1, s;
output f;
reg f;
always @(w0 or w1 or s)
begin
if(s==0)
assign f = w0;
else 
assign f = w1;
end
endmodule


module mux8to1(I, sel, Y);
input [7:0]I;
input [2:0]sel;
output Y;
reg Y;
always@(I or sel or Y)
begin
case(sel)
3'b000: Y=I[0];
3'b001: Y=I[1];
3'b010: Y=I[2];
3'b011: Y=I[3];
3'b100: Y=I[4];
3'b101: Y=I[5];
3'b110: Y=I[6];
3'b111: Y=I[7];
default: Y=1'b0;
endcase
end
endmodule

module mux16to1(w, s, f);
input [15:0]w;
input [3:0]s;
output f;
reg f;
reg s1, s2;
//always @(w or s)
//begin
mux8to1 first(w[7:0],s[2:0], s1);
mux8to1 second(w[15:8], s[2:0], s2);
mux2to1 final(s1, s2, s[3], f);
//end
endmodule


