// Single-digit BCD adder using a four-bit adder(s).

module halfadd(a, b, s, c);
input a, b;
output s, c;
assign s = a ^ b;
assign c = a & b;
endmodule

module fulladd(a, b, c_in, s, c_out);
input a, b, c_in;
output s, c_out;
wire w1,w2,w3;
halfadd ha1(a, b, w1, w2);
halfadd ha2(w1, c_in, s, w3);
assign c_out = w3 | w2;
endmodule

module l2q3(a, b, c_in, s, c_out);
input [3:0]a;
input [3:0]b;
input c_in;
output[3:0]s;
output c_out;

wire [3:0]w;
wire y, c0, c1, c2, c3, c4, c5;

fulladd fa1(a[0], b[0], c_in, w[0], c0);
fulladd fa2(a[1], b[1], c0, w[1], c1);
fulladd fa3(a[2], b[2], c1, w[2], c2);
fulladd fa4(a[3], b[3], c2, w[3], c3);
assign y = c3 | (w[3] & (w[2] | w[1]));
halfadd a1(w[1], y, s[1], c4);
halfadd a2(w[2], y, c4, s[2], c5);
halfadd a3(w[3], c5, s[3], c_out);
assign s[0] = w[0];
endmodule
