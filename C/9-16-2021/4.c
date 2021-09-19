
Example1:  a+b*c 


			Symbol				stack 					Postfix

			a											a
			-----------------------------------------------------
			+					+						a
								(Since stack 
								is empty we place 
								it directly)
			-----------------------------------------------------

			b					+						ab
			-----------------------------------------------------

			*					+*						ab 
								(since precedence
								of * is greater 
								the +, we need 
								multiplication to 
								be performed first)
			-----------------------------------------------------

			c					+*						abc
			-----------------------------------------------------
			Now popping the Stack
			-----------------------------------------------------

														
								+						abc*
			-----------------------------------------------------											
														abc*+
			-----------------------------------------------------






Example2:  a*b+c


			Symbol				stack 					Postfix

			a											a
			-----------------------------------------------------
			*					*						a

			-----------------------------------------------------

			b					*						ab
			-----------------------------------------------------

			+											ab*
								(Here elemet in
								stack has higher 
								precidence than the 
								one just read
								We should pop the 
								stack )
								
			-----------------------------------------------------
			+					+						ab*
			-----------------------------------------------------

			c					+						ab*c
			-----------------------------------------------------
			Now popping Elements
			-----------------------------------------------------
														ab*c+
			-----------------------------------------------------



//Implimentation using C language

/*

Infix Expression- Charecter Array

Postfix Expression- Charecter array

Stack - Char*

*/