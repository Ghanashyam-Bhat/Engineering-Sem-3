
// Write code for modules you need here
module fulladd(input wire a, b, cin, output wire sum, cout);
    wire [4:0] t;
    xor2 x0(a, b, t[0]);
    xor2 x1(t[0], cin, sum);

    and2 a0(a, b, t[1]);
    and2 a1(a, cin, t[2]);
    and2 a2(b, cin, t[3]);

    or2 o0(t[1], t[2], t[4]);
    or2 o1(t[3], t[4], cout);
endmodule	

module alunit (input wire op1, op0, input wire i0, i1, input wire carry, output wire o, output wire cout);
	wire z, x, y, sum, w;  
	xor2 one(op0, i1, z);
	fulladd two(i0, z, carry, sum, cout);    
	and2 three(i1, i0, x);
	or2 four(i1, i0, y);
	mux2 five(x, y, op0, w);
	mux2 six(sum, w, op1, o);
endmodule


module alu (input wire [1:0] op, input wire [15:0] i0, i1, output wire [15:0] o, output wire cout);

	// Declare wires here
	wire [14:0] c;
	// Instantiate modules here
	alunit a1(op[1], op[0], i0[0], i1[0], op[0], o[0], c[0]);
	alunit a2(op[1], op[0], i0[1], i1[1], c[0], o[1], c[1]);
	alunit a3(op[1], op[0], i0[2], i1[2], c[1], o[2], c[2]);
	alunit a4(op[1], op[0], i0[3], i1[3], c[2], o[3], c[3]);
	alunit a5(op[1], op[0], i0[4], i1[4], c[3], o[4], c[4]);
	alunit a6(op[1], op[0], i0[5], i1[5], c[4], o[5], c[5]);
	alunit a7(op[1], op[0], i0[6], i1[6], c[5], o[6], c[6]);
	alunit a8(op[1], op[0], i0[7], i1[7], c[6], o[7], c[7]);
	alunit a9(op[1], op[0], i0[8], i1[8], c[7], o[8], c[8]);
	alunit a10(op[1], op[0], i0[9], i1[9], c[8], o[9], c[9]);
	alunit a11(op[1], op[0], i0[10], i1[10], c[9], o[10], c[10]);
	alunit a12(op[1], op[0], i0[11], i1[11], c[10], o[11], c[11]);
	alunit a13(op[1], op[0], i0[12], i1[12], c[11], o[12], c[12]);
	alunit a14(op[1], op[0], i0[13], i1[13], c[12], o[13], c[13]);
	alunit a15(op[1], op[0], i0[14], i1[14], c[13], o[14], c[14]);
	alunit a16(op[1], op[0], i0[15], i1[15], c[14], o[15], cout);
endmodule
