var fs = require('fs') //Including Library File System
fs.readFile('test1.txt',function(err,data){ //There will be 2 parameters.1st one stores error is there is any
    if(err)
    {
        console.log(err);
    }
    else
    {
        setTimeout(()=>{ //Anonymous function (=>) //Like lambda function in Python //We can also use normal function
            console.log("The data present in the file is "+data)
        },2000)
    }
});
//console.log("End of File");
console.log("starting of the file")