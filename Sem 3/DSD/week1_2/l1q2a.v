// equation to be minimized :
// f(A, B, C, D) = ?m(1, 3, 4, 9, 10, 12) + D(0, 2, 5, 11)
// the minimized term of the equation :
// Ans = B'D + B'C + BC'D'
// using continuous assignment statements
module l1q2a(a, b, c, d, f);
 input a, b, c, d;
 output f;
 assign f = (~b & d) | (~b & c) | (b & ~c & ~d);
endmodule
