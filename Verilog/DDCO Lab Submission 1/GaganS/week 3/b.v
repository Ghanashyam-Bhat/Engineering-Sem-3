module invert(input wire i, output wire o1);
	assign o1=!i;
endmodule

module and2(input wire i0, i1, output wire o2);
	assign o2=i0&i1;
endmodule

module or2(input wire i0, i1, output wire o3);
	assign o3=i0|i1;
endmodule

module xor2(input wire i0, i1, output wire o4);
	assign o4=i0^i1;
endmodule

module nand2(input wire i0, i1, output wire o5);
	wire t;
	assign t=i0&i1;
	assign o5=!t;
endmodule

module fulladd(input wire a, b, cin, output wire sum, cout);
wire [4:0] t;
    xor2 x0(a, b, t[0]);
    xor2 x1(t[0], cin, sum);

    and2 a0(a, b, t[1]);
    and2 a2(b, cin, t[2]);
    and2 a3(a, cin, t[3]);

    or2 o0(t[1], t[2], t[4]);
    or2 o1(t[3], t[4], cout);
//assign t0=a^b;
//assign sum=t0^cin;
//assign t1=a&b;
//assign t2=a&cin;
//assign t3=b&cin;
//assign t4=t1|t2;
//assign cout=t3|t4;

endmodule

