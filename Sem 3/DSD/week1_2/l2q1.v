// Full adder

module l2q1(c_in, x, y, sum, c_out);
input c_in, x, y;
output sum, c_out;
// Calculating sum  
assign sum = c_in ^ x ^ y;
// calculating carry out = (x.y) + (y.c_in) + (c_in.x)
assign c_out = (x & y) | (y & c_in) | (c_in & x);
endmodule

