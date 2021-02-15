// 5 bit Johnson counter.

module DFlipFlop(D, clock, reset, Q); 
input D, clock, reset;  			
output Q; 
reg Q; 
 	 
always @(posedge clock) 
begin 
if(reset) 
Q <= 0; 
else if(D) 
Q <= 1;  	 	 		
else  	 	 	 			
Q <= 0; 
end 
endmodule

module l6q3b(clock, reset, Q);
input clock, reset;
output [0:4]Q;
wire [0:4]Q;

DFlipFlop d0(~Q[4], clock, reset, Q[0]);
DFlipFlop d1(Q[0], clock, reset, Q[1]);
DFlipFlop d2(Q[1], clock, reset, Q[2]);
DFlipFlop d3(Q[2], clock, reset, Q[3]);
DFlipFlop d4(Q[3], clock, reset, Q[4]);
endmodule
