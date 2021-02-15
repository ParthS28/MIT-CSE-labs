// Design and implement a full adder using 2 to 4 decoder(s) and other gates.

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

module l5q2(x, y, c_in, sum, c_out);
input x, y, c_in; 
output sum, c_out;  	 
wire [0:3] dec0w;  		
wire [0:3] dec1w;  		
wire [0:3] dec2w;  
dec2to4 d0({1'b0, x}, 1'b1, dec0w);  			
dec2to4 d1({c_in, y}, dec0w[1], dec1w);  		
dec2to4 d2({c_in, y}, dec0w[0], dec2w); 
or(sum, dec2w[3], dec1w[1], dec1w[2], dec1w[3]);  			
or(c_out, dec2w[1], dec2w[2], dec1w[0], dec1w[3]); 
endmodule 


