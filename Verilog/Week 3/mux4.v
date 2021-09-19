module MUX2(input wire a,b,s,output wire y);
assign y = (s==0)?a:b;
endmodule

module MUX4(input wire[3:0] i,input wire s1,s2,output wire y);
wire m,n;
MUX2 m1(i[0],i[1],s1,m);
MUX2 m2(i[2],i[3],s2,n);
MUX2 m3(m,n,s2,y);
endmodule
