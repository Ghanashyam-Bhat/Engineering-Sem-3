module mux2 (input wire i0, i1, s, output wire o);
assign o=(s==0)?i0:i1;
endmodule
