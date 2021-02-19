module jkf(j,k,clk,y);  
input j,k,clk;  
output y;  
reg y;  
always @(posedge clk)  
case({j,k})  
2'b00:y<=y;  
2'b01:y<=0;  
2'b10:y<=1;  
2'b11:y<=~y;  
endcase  
endmodule  

module l7q2_1(clk,control,out);  
input clk,control;  
output [2:0]out;  
wire a,b;  
jkf stage0(1,1,clk,out[0]);  
assign a = (control&&out[0])||(~control&&~out[0]);  
jkf stage1(a,a,clk,out[1]);  
assign b = (control&&out[0]&&out[1])||(~control&&~out[0]&&~out[1]);  
jkf stage2(b,b,clk,out[2]);  
endmodule 
