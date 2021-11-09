var fs= require('fs') //To include The library
var data = fs.readFileSync('test1.txt');//To read file synchornously (concept of blocking)
console.log(data.toString());
console.log("End File");

//But node JS works on the concept of non blocking generally(It reads the file asynchonously)
