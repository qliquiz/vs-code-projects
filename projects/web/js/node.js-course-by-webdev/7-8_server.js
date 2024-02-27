const http = require('http');

const PORT = 3000;

const server = http.createServer((req, res) => {
    console.log('Server request');
    console.log(req.url, req.method);

    // res.setHeader('Content-Type', 'text/html');
    // res.write('<h1>Answer!</h1>');
    res.setHeader('Content-Type', 'application/json');
    
    const data = JSON.stringify([
        {name: 'Artem', age: 18},
        {name: 'Alina', age: 18}
    ])

    res.end(data);
});

server.listen(PORT, 'localhost', (error) => {
    error ? console.log('Error') : console.log(`Listening port ${PORT}...`);;
});