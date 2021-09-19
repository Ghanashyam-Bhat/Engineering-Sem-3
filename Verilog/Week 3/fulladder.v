module fulladd(input wire a,b,cin,output wire sum, cout);
assign sum=(a^b)^cin;
assign cout=(a&b)|(b&cin)|(cin&a);
endmodule

module AND1(input wire a,b,output wire y);
assign y=a&b;
endmodule


module OR1(input wire a,b,output wire y);
assign y=a|b;
endmodule


module XOR1(input wire a,b,output wire y);
assign y=a^b;
endmodule

module Fulladd(input wire a,b,c,output wire sum,carry);
wire x,m,n,o,p;
XOR1 x1(a,b,x);
XOR1 x2(c,x,sum);

AND1 a1(a,b,m);
AND1 a2(b,c,n);
AND1 a2(c,a,o);

OR1 o1(m,n,p);
OR1 o2(o,p,carry);
endmodule

module Ripple(input wire[3:0] a,b,input wire Cin, output wire[3:0] s,output wire cout);
wire c[2:0];
Fulladd f1(a[0],b[0],cin,s[0],c[0]);
Fulladd f3(a[1],b[1],c[0],s[1],c[1]);
Fulladd f2(a[2],b[2],c[1],s[2],c[2]);
Fulladd f4(a[3],b[3],c[2],s[3],Cout);
endmodule


