//Copy and compare
const buff1 = Buffer.alloc(14,"Welcome to pes"); //If we give extra size, it prints garbage
const buff2  =Buffer.alloc(15,"welcome to Hell"); //If we allocate less size, the text gets trimmed
//Compareing the 2 strings
var result = buff1.compare(buff2);
console.log(buff1.toString() +" and "+buff2.toString())
if(result < 0)
{
    console.log("String 1 is smaller than string 2");
}
else if(result>0)
{
    console.log("String 1 is bigger than string 2");
}
else
{
    console.log("String 1 is bigger and string 2");
}

//Copying the the buffer
const buff3  =Buffer.alloc(20)
buff2.copy(buff3) //Copying the string of buffer 2 to buffer 3
console.log(buff3.toString())