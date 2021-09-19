//Infix and Postfix expression

//Infix Expression(Operator is lways in between operends) { a+b*c }
/* To solve infix expression we need to rescan the expression many times inorder solve expression
	based on precedence */
	
//Postfix expression: Can be solved with single scanf    { abc*+ }

//Converting Infix to Postfix involves stack memory



EXAPLES: 
1.
Infix: a+b+c

postfix:
ab+  --> t1
ab+c+

-----------------------------------------------------

2.
Infix: (a+b)*(c+d)

Postfix:
ab+ -->t1 
t1*(c+d)
cd+ -->t2
t1 * t2  = t1 t2*
ab+ cd+ *

-----------------------------------------------------


3.
Infix: a+b^c^d    (^ is power)

Postfix:
c ^ d = cd^ -->t1
a+b ^ t1
bt1 ^ --> t2
a + t2 = a t2 +
a b t1 ^ +
a b cd^ ^ +

-----------------------------------------------------

4.
Infix: a+b-c*d+(e^p)*f/g/h *i+j

Postfix:
e^p = ep ^ -->t1
a+b-c*d+t1 *f/g/h *i +j

c*d = cd* -->t2
a+b-t2+t1 *f/g/h *i +j

t1*f = t1 f * -->t3
a+b-t2+t3/g/h *i +j

t3/g = t3 g / -->temp
a+b-t2+temp1/h *i +j

temp1/h = temp h / --> t4

a+b-t2+t4*i +j

t4 * i = t4 i * -->t5
a+b-t2+t5+j

ab+ --> t6 

t6 - t2 + t5 +j

t6 - t2 = t6 t2 -   --> t7
t7 + t5 + j

t7 + t5 = t7 t5 +  --> t8

t8 + j = t8 j +

Answer:
t8 j +
t7 t5 + j +
t6 t2 -  t5 + j +
ab+ cd* -  t4 i *  + j +
ab+ cd* -  temp h /  i *  + j +
ab+ cd* -  t3 g / h /  i *  + j +
ab+ cd* -  t1 f *  g /h /  i *  + j +

ab+ cd* -  ep ^ f *  g /h /  i *  + j +

-----------------------------------------------------

5. 
Infix: a+(b*d/c)^e * (f+h/i)

Postfix:

-----------------------------------------------------

6.
Infix: (a+b-c)^d/e*(f-g)

Postfix:

-----------------------------------------------------