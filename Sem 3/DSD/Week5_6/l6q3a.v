module l6q3a(q, Clock, clear);
input Clock, clear;
output [0:3]q;
reg[0:3]q;

always@(posedge Clock or posedge clear)
if(clear==1)
q<=4'b0001;
else
begin
q[3]<=q[0];
q[2]<=q[3];
q[1]<=q[2];
q[0]<=q[1];
end
endmodule
