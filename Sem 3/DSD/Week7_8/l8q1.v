// Write and simulate the Verilog code to swap the contents of two registers using multiplexers. 

module mux2to1(S, W, f);
input S;
input [0:1]W;
output f;
assign f = S? W[1]: W[0];
endmodule

module l8q1(X, Y, Xout, Yout);
input X,Y;
output Xout,Yout;
wire M;
mux2to1 mux1(Y,{~X,X},M);
mux2to1 mux2(M,{~Y,Y},Yout);
mux2to1 mux3(Yout,{~M,M},Xout);
endmodule
