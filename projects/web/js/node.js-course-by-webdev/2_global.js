console.log(global);

console.log(__dirname); // полный путь до исполняемого файла
console.log(__filename); // весь путь до файла, включая имя и расширение

console.log(process); // куча свойств процесса
console.log(process.env); // develop/production etc.
console.log(process.argv); // аргументы командной строки
console.log(`Hello, ${process.argv[2]}`);

const url = new URL("https://webDev.com/path/name#test");
console.log(url.hostname);
console.log(url.href);
console.log(url.pathname);
console.log(url.hash);