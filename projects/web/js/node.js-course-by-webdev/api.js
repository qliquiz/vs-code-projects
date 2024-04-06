const axios = require('axios');
const DataFrame = require('dataframe-js').DataFrame;


const URL = 'https://api.sunrise-sunset.org/json';
// const city = 'Иркутск';
const lat = 52.2833; // широта
const lng = 104.2833; // долгота

const params = {
    lat: lat,
    lng: lng,
    date: '2024-04-06'
};

axios.get(URL, { params })
    .then((response) => {
        const data = response.data.results;
        const df = new DataFrame(data);
        const rows = df.toArray();
        const columns = df.listColumns();

        console.log('JSON');
        console.log(data);
        console.log();
        console.log('DataFrame');
        // Выводим названия столбцов
        console.log(columns.join('\t'));
        // Выводим значения построчно
        rows.forEach(row => {
            console.log(row.join('\t'));
        });
    })
    .catch((error) => {
        console.error(error);
});