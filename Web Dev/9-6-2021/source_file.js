//Comments In JS
//Single Line comment in JS
/* Multiline Comment*/


//Variable Declaraion in JS
/* 1.var
	2.const	: Value assigned is fixed,it cannot be changed
	 3. let: Reassigning of variable is not allowed
 */

var a = 23;  //using ; is not mandetory
alert(a);
var a = "PES";
alert(a);

//Here, Variable a is reassigned 
/* But if we use "let" command, reassigning of variable is not allowed*/

/* let
The below code goves error, so JS file wont get executed 
var b = 23;  
alert(b);
let b = "PES";
alert(b);
 */
 
 /* const
const a = 23;
alert(a);
a = 56; //This wont get executed
alert(a);
*/


//there is no provision to mention Data type. It directly takes data type based on the type of data provided
/*
Datatypes
Numbers : var a= 50;
String : var name = "PES";
Boolean: var bool = true;
const var PI = 3.14;
object(new) ; //To create not keyword
*/

/*
Declaraion:
1.
var a;
a = 50;

2.
var b = 50+60;
*/

/*Conditional Statements
-if
-if else 
-if elseif
*/

/*Looping
-for 
-while 
-for ... in 
*/

/*Operators
-Arithmatic Operator : + ,-,* ,/, % ,**
-Relational Operator : != , > , < , <= , >= , == , ===(equal to) , !==
-Increment and Decrement : ++ , --
-Ternary Operator : ?
-Logical Operator : && , || , ! 
-Bitwise : | , & , ^ ,~
*/

/*Output Function
1.alert()
2.confirm()   //It comes with OK and cancel; For Ok, True will be returned ;For cancel , False will be returned
3.document.write()
4.console.log() //Same doxument,write , but helps in debugging //We can see output in console of Inspect element(This is just for Debugging)
5.document.writel()   //Similar to document.write It give 1 space between 2 document.writel
6. prompt()  //We can enter text inside popup
*/

/*When we open website , alert() , confirm () ,propmpt() gets executed first, no matter when they are coded  
because these are popup messages*/


/*Datstructures
1.Array :
	var a = [..., ..., .. ,... ]
	//Accessig element is same as C language
	//We can also use dictionary type of data inside Array
	
	
Built-in function for array:
1. array_name.pop() : removes last element and returns the value
2. array_name.shift():Removes first element from array and returns the deleted value
3.array_name.unshift() : Used to add the element to array
4.array_name.reverse() : Reverses the array
*/


/* User defined functions in JS

syntax: 

function fun_name(par,par2)
{
	//All the operations just like high end laguages
	//We can call these fuctions from HTML also
}

*/



/*Built in functions

1. setInterval() //1st parameter is function to be called, 2nd is time interval
					//This is to call a function after some time for infinite time 
2. setTimeout() //1st parameter is function to be called, 2nd is time interval
					//This is to call a function after some time only once

*/