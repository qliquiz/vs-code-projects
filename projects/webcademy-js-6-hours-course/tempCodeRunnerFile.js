const myPromise = new Promise((resolve, reject) => {
    setTimeout(() => {
        // сделали какой-то запрос на сервер
        const response = true; // получили какой-то ответ
        if (response) {
            resolve('OK');
        } else {
            reject('NOT OK');
        }
    }, 1000);
}).then((data) => {
    console.log(data)
}).catch((data) => {
    console.log(data)
});