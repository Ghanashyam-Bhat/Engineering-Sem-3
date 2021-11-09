/*
Buffer : Memory allocation
    alloc(size,data)
    concat([str1,str2,....],size)
*/

const buff1 = Buffer.alloc(10,'hi Welcome');
const buff2 = Buffer.alloc(12,'to pes university');

console.log(buff1.toString());
console.log(buff2.toString());
//Since we are allocating memory using alloc function, we need to use .toString() for displaying

//To find total length
const total_length = buff1.length + buff2.length;
console.log(total_length);

//String Functions
const buff = Buffer.concat([buff1,buff2],total_length);
console.log(buff.toString())
console.log(buff.length)
