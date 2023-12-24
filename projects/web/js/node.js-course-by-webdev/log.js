const EventEmitter = require('events');
const util = require('util');

class Logger {
    log = (msg) => {
        console.log(msg);
        this.emit('some_event', {id: 1, text: 'Event task text!'}); // создаем событие some_event
    }
}

util.inherits(Logger, EventEmitter); // расширяем класс Logger до EventEmitter(наследуемся)

module.exports = Logger; // закидываем новый класс в модули