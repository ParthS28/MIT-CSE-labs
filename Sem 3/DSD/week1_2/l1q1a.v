//f1 =ac’+bc+b’c’
module l1q1a(a, b, c, f);
input a, b, c;
output f;
and(x1, a, ~c);
and(x2, b, c);
and(x3, ~b, ~c);
or(f, a, b, c);
endmodule
