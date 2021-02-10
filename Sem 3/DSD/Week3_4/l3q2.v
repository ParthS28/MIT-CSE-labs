// Write and simulate the Verilog code for a 4-bit comparator using 2-bit comparators.

module comp2bit(x0, y0, x1, y1, l, g, e);
input x0, y0, x1, y1;
output l, g, e;
wire i, j;
assign j = ~(x1 ^ y1);
assign i = ~(x0 ^ y0);
assign e = i & j;
assign g = (x1 & ~y1)|(j & x0 & y0);
assign l = ~(g | e);
endmodule

// 4 bit comp
module l3q2(x, y, l, g, e);
input [3:0]x;
input [3:0]y;
output l, g, e;
wire l1, l2, g1, g2, e1, e2;
comp2bit c1(x[0], y[0], x[1], y[1], l1, g1, e1);
comp2bit c2(x[2], y[2], x[3], y[3], l2, g2, e2);
assign e = e1 & e2;
assign g = g2 | (e2 & g1);
assign l = l2 | (e2 & l1);
endmodule

