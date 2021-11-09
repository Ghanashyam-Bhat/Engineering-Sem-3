var http = require("http");

http.createServer(function(req,res){
    res.write("Welcome to Node JS");
    res.end();
}).listen(8080)//Port number for Local host server is 8080 or 8000or 5000 or 3000


//node node1.js
//http://localhost:8080/

/*In treditional programmign languages, task is lined up and executed one after the other
But in Node JS, all the task is executed simulteniously
*/