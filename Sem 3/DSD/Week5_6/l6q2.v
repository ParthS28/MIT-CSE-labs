// Write behavioral Verilog code for a positive edge-triggered JK FF with synchronous active high reset

module l6q2(J, K, clock, reset, Q);
input J, K, clock, reset;
output Q;
reg Q;

always @(posedge clock or posedge reset)
begin
case({J, K})
0: Q <= Q;
1: Q <= 0;
2: Q <= 1;
3: Q <= ~Q;
endcase
if(reset==1)
Q <= 0;
end
endmodule
