const fs = require('fs');
const zlib = require('zlib');

const readStream = fs.createReadStream('projects/web/js/node.js-course-by-webdev/txt/read-stream.txt');
const writeStream = fs.createWriteStream('projects/web/js/node.js-course-by-webdev/txt/write-stream.txt');
const compressStream = zlib.createGzip();

/* readStream.on('data', (chunk) => {
    writeStream.write('\n ---CHUNK-START--- \n');
    writeStream.write(chunk);
    writeStream.write('\n ---CHUNK-END--- \n');
}); */

const handleError = () => {
    console.log('Error');
    readStream.destroy();
    writeStream.end('Finished with error...');
};

readStream.on('error', handleError).pipe(compressStream).pipe(writeStream).on('error', handleError);