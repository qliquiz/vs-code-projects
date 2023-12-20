const os = require('os');
const cluster = require('cluster');

/* console.log(os.platform());
console.log(os.arch());
console.log(os.cpus());
console.log(os.cpus().length); */

if (cluster.isMaster) {
    for (let i = 0; i < os.cpus().length - 2; i++) {
        cluster.fork()
    }
    cluster.on('exit', (worker) => {
        console.log(`Воркер с pid = ${worker.process.pid} умер`);
        cluster.fork();
    })
} else {
    console.log(`Процесс ${process.pid} запущен`);
    setInterval(() => console.log(`Процесс ${process.pid} всё ещё работает`), 5000);
}
