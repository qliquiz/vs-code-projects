const Logger = require('./5_log');

const logger = new Logger();

logger.on('some_event', (args) => { // обрабатываем событие some_event
    const {id, text} = args;
    console.log(id, text);
});

logger.log('User logged!');