// Write behavioral Verilog code for a negative edge triggered T FF with asynchronous active low reset.

module l6q1(T, clock, reset, Q);
input T, clock, reset;
output Q;
reg Q;
always @(negedge clock)
begin
if(T==1)
Q <= ~Q;
if(reset==0)
Q <= 0;
end
endmodule


