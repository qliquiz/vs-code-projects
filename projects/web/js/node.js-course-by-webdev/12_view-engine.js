const express = require('express');
const path = require('path');
const server = express();
const PORT = 3000;

const createPath = (page) => path.resolve(__dirname, 'views', `${page}.html`);

server.listen(PORT, (error) => {
    error ? console.log('Error') : console.log(`Listening port ${PORT}...`);;
});

server.get('/', (req, res) => {
    res.sendFile(createPath('index'));
});

server.get('/contacts', (req, res) => {
    res.sendFile(createPath('contacts'));
});

server.get('/posts/:id', (req, res) => {
    res.sendFile(createPath('post'));
});

server.get('/posts', (req, res) => {
    res.sendFile(createPath('posts'));
});

server.get('/add-post', (req, res) => {
    res.sendFile(createPath('add-post'));
});

server.get('/about-us', (req, res) => {
    res.sendFile(createPath('contacts'));
});

server.use((req, res) => {
    res.status(404).sendFile(createPath('error'));
});