const fs = require('fs');
const path = require('path');

console.log();

/* // fs.mkdirSync(path.resolve(__dirname, 'dir')); // синхронное создание папки dir (make directory)
console.log('START');
fs.mkdir(path.resolve(__dirname, 'dir'), (error) => {
    if (error) {
        console.log(error);
        return;
    }
    else console.log('Папка создана.');
}); // aсинхронное создание папки dir (make directory)
console.log('END'); */

/* fs.rmdir(path.resolve(__dirname, 'dir'), (error) => {
    if (error) throw error;
}); // асинхронное удаление папки dir (remove directory) */

/* fs.writeFile(path.resolve(__dirname, 'text.txt'), 'bla bla bla', () => {
    if (error) throw error;
    console.log('Файл создан.');
    fs.appendFile(path.resolve(__dirname, 'text.txt'), ' add to end', () => {
        if (error) throw error;
        console.log('Текст добавлен.');
    }); // функция добавляет текст
}); // функция перезаписывает текст, не добавляет, но добавляет файл, если его нет */
