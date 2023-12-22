const fs = require('fs');

fs.readFile('./file-system.txt', 'utf8', (error, data) => {
    console.log(data);
});
