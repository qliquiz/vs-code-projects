const fs = require('fs');

fs.readFile('./file-system.txt', 'utf8', (error, data) => {
    fs.mkdirSync('./new-dir', () => {});
    fs.writeFileSync('./new-dir/new-file.txt', `${data} + new text`, (error) => {
        error ? console.log(error) : null;
    });
});

setTimeout(() => {
    if (fs.existsSync('./new-dir/new-file.txt')) {
        fs.unlink('./new-dir/new-file.txt', () => {});
        setTimeout(() => { fs.rmdir('./new-dir', () => {}) }, 2000);
    }
}, 4000);