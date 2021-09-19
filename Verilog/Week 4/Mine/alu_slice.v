module alu_slice(input wire io,i1,op0,op1,cin,output wire o,cout)
wire t1,t2,t3,t4,t5;
assign XOR1 x1(op0,i1,t1);
assign Fulladd f1(i1,t1,cin,t2,cout);
assign AND1 and1(i0,i1,t3);
assign OR1  or1(i0,i1,t4);
assign MUX2 mx1(t3,t4,op0,t5);
assign MUX2 mx2(t5,t2,op1,o);
endmodule
