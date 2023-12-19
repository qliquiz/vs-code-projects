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

const writeFileAsync = async (path, data) => {
    return new Promise((resolve, reject) => fs.writeFile(path, data, (error) => {
        if (error) return reject(error.message);
        else resolve();
    }))
}

const appendFileAsync = async (path, data) => {
    return new Promise((resolve, reject) => fs.appendFile(path, data, (error) => {
        if (error) return reject(error.message);
        else resolve();
    }))
}

const readFileAsync = async (path) => {
    return new Promise((resolve, reject) => fs.readFile(path, {encoding: 'utf-8'}, (error, data) => {
        if (error) return reject(error.message);
        else resolve(data);
    })) 
}

const removeFileAsync = async (path) => {
    return new Promise((resolve, reject) => fs.rm(path, (error) => {
        if (error) return reject(error.message);
        else resolve();
    }))
}

/* writeFileAsync(path.resolve(__dirname, 'text.txt'), 'data ')
    .then(() => appendFileAsync(path.resolve(__dirname, 'text.txt'), '123 '))
    .then(() => appendFileAsync(path.resolve(__dirname, 'text.txt'), '456 '))
    .then(() => appendFileAsync(path.resolve(__dirname, 'text.txt'), '789 '))
    .then(() => readFileAsync(path.resolve(__dirname, 'text.txt')))
    .then(data => console.log(data))
    .catch(error => console.log(error));

removeFileAsync(path.resolve(__dirname, 'text.txt'))
    .then(() => console.log('The file was removed')); */

// Через переменную окружения передать строку, записать ее в файл,
// прочитать файл, посчитать кол-во слов в файле и записать
// их в новый файл count.txt, затем удалить первый файл.

const text = process.env.TEXT || '';

writeFileAsync(path.resolve(__dirname, 'file.txt'), text)
    .then(() => readFileAsync(path.resolve(__dirname, 'file.txt')))
    .then(data => data.split(' ').length)
    .then(count => writeFileAsync(path.resolve(__dirname, 'count.txt'), `Количество слов: ${count}`))
    .then(() => removeFileAsync(path.resolve(__dirname, 'file.txt')));