module tb;
reg t_a;
reg t_b;
wire t_x,t_y;
//instantiate
hadd add3(.a(t_a),.b(t_b),.s(t_x),.c(t_y));
initial begin $dumpfile("dump.vcd");
$dumpvars(0,tb);
end
initial begin $monitor(t_a,t_b,t_x,t_y); //displays the content of the register
t_a=1'b0;//1 bit input
t_b=1'b0;
#10 //time nanosecs
t_a=1'b0;//1 bit input
t_b=1'b1;
#10 //time nanosecs
t_a=1'b1;//1 bit input
t_b=1'b0;
#10 //time nanosecs
t_a=1'b1;//1 bit input
t_b=1'b1;
#10 //time nanosecs
t_a=0;//inorder to see the last input
t_b=0;
end
endmodule

