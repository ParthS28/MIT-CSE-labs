// Design and simulate the circuit with 3 to 8 decoder(s) and external gates to implement the functions below.
// F(a, b, c, d)= Sm(2,4,7,9) G (a, b, c, d)= Sm (0,3,15) H(a, b, c, d)= Sm(0,2,10,12)

module dec2to4(W, En, Y);
input [1:0]W;
input En;
output [0:3]Y;
reg [0:3]Y;
always @(W or En)
begin
if(En==0)
Y=4'b0000;
else
case(W)
0:Y=4'b1000;
1:Y=4'b0100;
2:Y=4'b0010;
3:Y=4'b0001;
endcase
end
endmodule

module dec3to8(W,En,Y);  		
input [2:0]W;  			
input En;  			
output [0:7]Y; 
wire[0:3]M; 
 	
dec2to4 dec1({1'b0, W[2]},En,M);  		
dec2to4 dec2(W[1:0],M[0],Y[0:3]);  		
dec2to4 dec3(W[1:0],M[1],Y[4:7]); 
endmodule 

module l5q3(W, En, f, g, h);
input [3:0]W;
input En;
output f, g, h;
wire [0:7] temp0;  		
wire [0:7] temp1;  		
wire [0:7] temp2;  		
wire [0:7] temp3;  		
wire [0:7] temp4;  	
dec3to8 dec0({1'b0, W[3], W[2]}, En, temp0);  	
dec3to8 dec1({1'b0, W[1], W[0]}, temp0[0], temp1);  	
dec3to8 dec2({1'b0, W[1], W[0]}, temp0[1], temp2);  	

dec3to8 dec3({1'b0, W[1], W[0]}, temp0[2], temp3);  	
dec3to8 dec4({1'b0, W[1], W[0]}, temp0[3], temp4); 

or(f, temp1[2], temp2[0], temp2[3], temp3[1]);  		
or(g, temp1[0], temp1[3], temp4[3]);  	
or(h, temp1[0], temp1[2], temp3[2], temp4[0]); 
endmodule 


