module fulladd(input wire a,b,cin,output wire sum, cout);
assign sum=(a^b)^cin;
assign cout=(a&b)|(b&cin)|(cin&a);
endmodule

module AND1(input a,b,output y);
assign y=a&b;
endmodule


module OR1(input a,b,output y);
assign y=a|b;
endmodule


module XOR1(input a,b,output y);
assign y=a^b;
endmodule

module Fulladd(input a,b,c,output sum,carry);
wire x,m,n,o,p;
XOR1 x1(a,b,x);
XOR1 x2(c,x,sum);

AND1 a1(a,b,m);
AND1 a2(b,c,n);
AND1 a3(c,a,o);

OR1 o1(m,n,p);
OR1 o2(o,p,carry);
endmodule

