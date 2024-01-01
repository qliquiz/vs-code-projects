const fs = require('fs');
const readStream = fs.createReadStream('text-stream.txt');

readStream.on('data', (chunk) => {
    console.log('-----------');
    console.log(chunk.toString());
});
