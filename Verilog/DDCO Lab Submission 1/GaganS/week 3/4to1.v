module mux4 (input wire [3:0] i, input wire j1, j0, output wire o);
  wire  t0, t1;

mux2 m1(i[0],i[1],j1,t0);
mux2 m2(i[2],i[3],j1,t1);
mux2 m3(t0,t1,j0,o);

endmodule

