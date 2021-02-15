// f(A,B,C,D)=pM(2,6,8,9,10,11,14)
// Ans = A'C' + A'D + BC' + BD

module l1q3(a, b, c, d, f);
input a, b, c, d;
output f;
nand(x1, ~a, ~c);
nand(x2, ~a, d);
nand(x3, b, ~c);
nand(x4, b, d);

nand(f, x1, x2, x3, x4);
endmodule
