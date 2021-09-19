module TB;
reg [0:3]ii;
reg s0;
reg s1;
wire yy;
initial
begin
$dumpfile("dump.vcd");
$dumpvars(0, TB);
end
MUX4 newMUX(.i(ii), .s1(s0),.s2(s1),.y(yy));
initial
begin
ii = 4'b0001;
s0=1'b0;
s1=1'b0;
#5
ii = 4'b1000;
#5
ii = 4'b0001;
s0=1'b1;
s1=1'b1;
#5
ii = 4'b0000;
s0=1'b1;
s1=1'b0;
end
endmodule
