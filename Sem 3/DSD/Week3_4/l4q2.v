module dec2to4(w, en, y);
input [1:0]w;
input en;
output [3:0]y;
reg [3:0]y;
always @(w or en)
begin
if(en == 0)
y = 15;
else
begin
case (w)
0:y = 14;
1:y = 13;
2:y = 11;
3:y = 7;
endcase
end
end
endmodule


module l4q2(w,y,en);
input en;
input [3:0]w;
output [15:0]y;
wire [3:0]x;
dec2to4 stage0(w[3:2],en,x[3:0]);
dec2to4 stage1(w[1:0],~x[0],y[3:0]);
dec2to4 stage2(w[1:0],~x[1],y[7:4]);
dec2to4 stage3(w[1:0],~x[2],y[11:8]);
dec2to4 stage4(w[1:0],~x[3],y[15:12]);
endmodule
