const express = require('express');
const path = require('path');
const server = express();
const PORT = 3000;

server.set('view engine', 'ejs');

const createPath = (page) => path.resolve(__dirname, 'ejs-views', `${page}.ejs`);

server.listen(PORT, (error) => {
    error ? console.log('Error') : console.log(`Listening port ${PORT}...`);;
});

server.get('/', (req, res) => {
    const title = 'Home';
    res.render(createPath('index'), {title});
});

server.get('/contacts', (req, res) => {
    const title = 'Contacts';
    const contacts = [
        {name: 'YouTube', link: 'http://youtube.com/YauhenKavalchuk'},
        {name: 'Twitter', link: 'http://github.com/YauhenKavalchuk'},
        {name: 'GitHub', link: 'http://twitter.com/YauhenKavalchuk'}
    ];
    res.render(createPath('contacts'), {contacts, title});
});

server.get('/posts/:id', (req, res) => {
    const title = 'Post';
    res.render(createPath('post'), {title});
});

server.get('/posts', (req, res) => {
    const title = 'Posts';
    res.render(createPath('posts'), {title});
});

server.get('/add-post', (req, res) => {
    const title = 'Add Post';
    res.render(createPath('add-post'), {title});
});

server.get('/about-us', (req, res) => {
    const title = 'Home';
    res.render(createPath('contacts'), {title});
});

server.use((req, res) => {
    const title = 'Error';
    res.status(404).render(createPath('error'), {title});
});