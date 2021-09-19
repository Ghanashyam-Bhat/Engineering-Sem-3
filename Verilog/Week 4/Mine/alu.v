
// Write code for modules you need here

module alu (input wire [1:0] op, input wire [15:0] i0, i1,
    output wire [15:0] o, output wire cout);


// Declare wires here
wire c[14:0];
// Instantiate modules here

assign alu_slice alu1(i0[0],i1[0],op[0],op[1],op[0],o[0],c[0]);

assign alu_slice alu2(i0[1],i1[1],op[0],op[1],c[0],o[1],c[1]);

assign alu_slice alu3(i0[2],i1[2],op[0],op[1],c[1],o[2],c[2]);

assign alu_slice alu4(i0[3],i1[3],op[0],op[1],c[2],o[3],c[3]);

assign alu_slice alu5(i0[4],i1[4],op[0],op[1],c[3],o[4],c[4]);

assign alu_slice alu6(i0[5],i1[5],op[0],op[1],c[4],o[5],c[5]);

assign alu_slice alu7(i0[6],i1[6],op[0],op[1],c[5],o[6],c[6]);

assign alu_slice alu8(i0[7],i1[7],op[0],op[1],c[6],o[7],c[7]);

assign alu_slice alu9(i0[8],i1[8],op[0],op[1],c[7],o[8],c[8]);

assign alu_slice alu10(i0[9],i1[9],op[0],op[1],c[8],o[9],c[9]);

assign alu_slice alu11(i0[10],i1[10],op[0],op[1],c[9],o[10],c[10]);

assign alu_slice alu12(i0[11],i1[11],op[0],op[1],c[10],o[11],c[11]);

assign alu_slice alu13(i0[12],i1[12],op[0],op[1],c[11],o[12],c[12]);

assign alu_slice alu14(i0[13],i1[13],op[0],op[1],c[12],o[13],c[13]);

assign alu_slice alu15(i0[14],i1[14],op[0],op[1],c[13],o[14],c[14]);

assign alu_slice alu16(i0[15],i1[15],op[0],op[1],c[14],o[15],cout);

endmodule
