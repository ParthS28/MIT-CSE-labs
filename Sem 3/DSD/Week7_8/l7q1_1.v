module tf(t,clk,q);  
input t,clk;  
output q;  
reg q;  
always @(negedge clk)  
if(!t)  
q<=q;  
else  
q<=~q;  
endmodule  

module l7q1_1(clk,q);  
input clk;  
output [3:0]q;  

tf stage0(1,clk,q[0]);  
tf stage1(1&&q[0],clk,q[1]);  
tf stage2(1&&q[0]&&q[1],clk,q[2]);  
tf stage3(1&&q[0]&&q[1]&&q[2],clk,q[3]);  
endmodule
