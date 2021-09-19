module fulladd(input wire a,b,cin,output wire sum,cout);
assign t0=a^b;
assign sum=t0^cin;
assign t1=a&b;
assign t2=a&cin;
assign t3=b&cin;
assign t4=t1|t2;
assign cout=t3|t4;

endmodule

