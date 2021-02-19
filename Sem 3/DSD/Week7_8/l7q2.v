module l7q2(clk, reset, up, c);
input clk, reset, up;
output [2:0]c;
reg [2:0]c;
always @(posedge clk)
begin
if(!reset)
c<=0;
else
begin
if(up)
c<=c+1;
else
c<=c-1;
end
end
endmodule

