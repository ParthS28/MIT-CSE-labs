module full_adder(c_in, x, y, sum, c_out);
input c_in, x, y;
output sum, c_out;
// Calculating sum  
assign sum = c_in ^ x ^ y;
// calculating carry out = (x.y) + (y.c_in) + (c_in.x)
assign c_out = (x & y) | (y & c_in) | (c_in & x);
endmodule

module l2q2(S, C, V, A, B, Op);
output [3:0] S; // The 4-bit sum/difference.
output C; // The 1-bit carry/borrow status.
output V; // The 1-bit overflow status.
input [3:0] A; // The 4-bit augend/minuend.
input [3:0] B; // The 4-bit addend/subtrahend.
input Op; // The operation: 0 => Add, 1=>Subtract.
 
wire C0; // The carry out bit of fa0, the carry in bit of fa1.
wire C1; // The carry out bit of fa1, the carry in bit of fa2.
wire C2; // The carry out bit of fa2, the carry in bit of fa3.
wire C3; // The carry out bit of fa2, used to generate final carry/borrrow.
wire B0;
wire B1;
wire B2;
wire B3;
xor(B0, B[0], Op);
xor(B1, B[1], Op);
xor(B2, B[2], Op);
xor(B3, B[3], Op);
xor(C, C3, Op); // Carry = C3 for addition, Carry = not(C3) for subtraction.
xor(V, C3, C2); // If the two most significant carry output bits differ, then we have an overflow.
 
full_adder fa0(Op, A[0], B0, S[0], C0);
full_adder fa1(C0, A[1], B1, S[1], C1);
full_adder fa2(C1, A[2], B2, S[2], C2);
full_adder fa3(C2, A[3], B3, S[3], C3);
//full_adder fa0(S[0], C0, A[0], B0, Op); // Least significant bit.
//full_adder fa1(S[1], C1, A[1], B1, C0);
//full_adder fa2(S[2], C2, A[2], B2, C1);
//full_adder fa3(S[3], C3, A[3], B3, C2); // Most significant bit.
endmodule



