// ========== Path ========== \\

const path = require('path');

console.log();
console.log('Путь: ', path.join(__dirname, 'first', 'second'));
console.log('Поднялись выше: ', path.join(__dirname, '..'));
console.log('Получить абсолютный путь: ', path.resolve('first', 'second'));
console.log('Получить абсолютный путь от слеша: ', path.resolve('/first', 'second'));
const full_path = path.resolve('file.js');
console.log('Парсинг пути: ', path.parse(full_path));
console.log('Разделитель в ОС: ', path.sep);
console.log('Проверка на абсолютный путь: ', path.isAbsolute(full_path));
console.log('Название файла', path.basename(full_path));
console.log('Расширение файла', path.extname(full_path));

// ========== URL ========== \\

const siteURL = 'http://localhost:8080/users?id=2222';
const url = new URL(siteURL);

console.log(url);