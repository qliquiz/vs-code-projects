const express = require('express');
const path = require('path');
const server = express();
const PORT = 3000;

const createPath = (page) => path.resolve(__dirname, 'views', `${page}.html`);

server.listen(PORT, (error) => {
    error ? console.log('Error') : console.log(`Listening port ${PORT}...`);;
});

server.get('/', (req, res) => {
    res.sendFile(createPath('index')); // экспрессу не нужен ContentType
});

server.get('/contacts', (req, res) => {
    res.sendFile(createPath('contacts')); // экспрессу не нужен ContentType
});

server.get('/about-us', (req, res) => {
    res.redirect('contacts');
});

server.use((req, res) => {
    res.status(404).sendFile(createPath('error'));
});