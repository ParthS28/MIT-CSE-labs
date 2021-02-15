// f(A,B,C,D) = ?M(6,9,10,11,12) + D(2,4,7,13)
// Ans = B'C'D' + ABC + A'D

module l1q2b(a, b, c, d, f);
input a, b, c, d;
output f;
assign f = (~a & d) | (~b & ~c & ~d) | (a & b & c);
endmodule
