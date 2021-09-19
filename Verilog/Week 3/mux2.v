module MUX2(input wire a,b,s,output wire y);
assign y = (s==0)?a:b;
endmodule
