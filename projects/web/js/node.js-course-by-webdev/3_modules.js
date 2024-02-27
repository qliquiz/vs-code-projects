/* Записали в 1_test.js:
module.exports = {
    userName,
    sayHi
} */

const os = require("os");
const { userName: user, sayHi } = require("./1_test");

console.log(user);

const name = "Tommy";

console.log(sayHi(name));

module.exports = name;

console.log(os.platform(), os.release());