// ====================Выбор коллекции селекторов====================

/* const headings = document.querySelectorAll('h2'); // через for of
for (let heading of headings){
    heading.classList.add('green'); 
}

const paragraphs = document.querySelectorAll('p'); // через forEach
paragraphs.forEach(function(p){
    p.classList.add('red-text');
}) */

/* document.getElementsByClassName('link'); // выбор коллекции элементов по CSS классу
document.getElementsByTagName('h1'); // выбор коллекции элементов по Тегу
document.getElementById('header'); // выбор одного элемента по ID */

// ====================Работа с CSS классами====================

/* element.classList.add() - добавляет CSS класс
element.classList.remove() - удаляет CSS класс
element.classList.toggle() - добавляет CSS класс, если его не было, или удаляет, если он был
element.classList.contains() - возращает true/false в зависимости от того, существует такой CSS класс или нет */

/* const secondHeading = document.querySelector('h2');
secondHeading.classList.toggle('green');
secondHeading.classList.toggle('red'); */

// ====================Работа с атрибутами====================

/* getAttribute(attrName) - возвращает значение указанного атрибута
setAttribute(name, value) - добавляет атрибут и его значение к элементу
hasAttribute(attrName) - возвращает true/false в зависимости от того, имеется такой атрибут у элемента или нет
removeAttribute(attrName) - удаляет атрибут

toggleAttribute(name, force) - добавляет атрибут, если его не было, или удаляет, если он был
hasAttributes() - возвращает true/false в зависимости от того, имеются какие-либо атрибуты у элемента или нет
getAttributesNames() - возвращает названия атрибутов элемента */

/* const img = document.querySelector('#logo'); // нашли html-элемент по ID='logo'
img.src = './img/php.png'; // изменили атрибут src, поменяв картинку
img.setAttribute('width','200'); // добавили атрибут width=200
img.src = './img/js.png'; //вернули исходную картинку
const btn = document.querySelector('#button');
btn.value = 'Текст для кнопки'; */

// ====================Работа с событиями====================

// Кнопка
/* const img = document.querySelector('#logo');
const button = document.querySelector('#button');
button.value = 'Удалить';

button.onclick = function(){
    console.log('Click!');
}

button.addEventListener('click', function(){
    console.log('Click!');
}) */

// Ввод текста
/* const inputText = document.querySelector('#input-text');
const textBlock = document.querySelector('#text-block');

inputText.addEventListener('input', () => {
    textBlock.innerText = inputText.value;
}); */

// Event
/* const list = document.querySelector('#list');

list.addEventListener('click', function(event) {
    console.log(event.target);
}); */

// ====================Создание и копирование элементов====================

/* document.createElement('tag-name') - создать элемент
element.innerHTML = '' - изменить HTML-содержимое внутри элемента
node.innerText = '' - изменить текстовое содержимое внутри элемента
node.cloneNode() - копировать элемент(true - с внутренним содержимым, false - без содержимого)
element.append(nodesOrDOMStrings) - вставить элемент внутрь другого элемента
element.remove() - удалить элемент */

/* // Выбор контейнера
const container = document.querySelector('#elementsContainer');

// Создание заголовка
const newHeader = document.createElement('h1');
newHeader.innerText = 'Новый заголовок';
container.append(newHeader);

// Копирование шапки
const mainHeader = document.querySelector('header');
const copyOfMainHeader = mainHeader.cloneNode(true);
container.append(copyOfMainHeader);

// Вставка разметки через строки
const htmlExample = '<h2>Ещё один заголовок</h2>';
container.insertAdjacentHTML('beforeend', htmlExample);

// Вставка разметки через шаблонные строки
const title = 'Текст заголовка';
const htmlExample2 = `<h3>${title}</h3>`;
container.insertAdjacentHTML('beforeend', htmlExample2); */

// ====================ToDo[практика]====================
/* const todoList = document.querySelector('#todo-list');
const todoForm = document.querySelector('#todo-form');
const todoInput = document.querySelector('#todo-input');

todoForm.addEventListener('submit', formHandler);

function formHandler(event) {
    event.preventDefault();
    // Получаем название задачи из инпута
    const taskText = todoInput.value;

    // Создаём тег li через разметку
    // const li = `<li>${taskText}</li>`;
    // Добавляем разметку на страницу
    // todoList.insertAdjacentHTML('beforeend', li); // можно было заменить эти три пункта строкой todoList.insertAdjacentHTML('beforeend', `<li>${todoInput.value}</li>`);
    
    // Создаем тег li с помощью создания элемента
    const newTask = document.createElement('li');
    newTask.innerText = taskText;
    // Создаем кнопку "Удалить"
    const deleteBttn = document.createElement('button');
    deleteBttn.setAttribute('role', 'button');
    deleteBttn.innerText = 'Удалить';
    deleteBttn.style['margin-left'] = '10px';
    deleteBttn.addEventListener('click', function() {
        this.closest('li').remove();
    });
    // Добавляем элемент на страницу
    todoList.append(newTask);
    newTask.append(deleteBttn);
    // Очищаем поле ввода
    todoInput.value = '';
    // Фокус на поле ввода
    todoInput.focus();
} */

// ====================setInterval====================
/* const interval = setInterval(() => {console.log('Tick-Tack!')}, 1000); // каждую секунду в консоль будет выводиться 'Tick-Tack!'
clearInterval(interval); // остановили */

// ====================setTimeOut====================
/* const timer = setTimeout(() => {console.log('Boom!', 5000)}); // код запустится через 5 сек
clearInterval(timer); // отменит выполнение таймаута */

// ====================setInterval + setTimeOut (Таймер)====================
/* const counter = setInterval(() => {console.log('+')}, 1000); // каждую секунду выводит "+"
setTimeout(() => {clearInterval(counter)}, 5000); // останавливает через 5 сек */

// ====================Секундомер[практика]====================
/* let counter = 0;
let timerID;
const counterElement = document.querySelector('#counter');
const btnStart = document.querySelector('#start');
const btnStop = document.querySelector('#stop');
const btnReset = document.querySelector('#reset');

btnStart.onclick = () => {
    timerID = setInterval(() => {
        counter++;
        counterElement.innerText = counter;
    }, 1000);
}

btnStop.onclick = () => {
    clearInterval(timerID);
}

btnReset.onclick = () => {
    clearInterval(timerID);
    counter = 0;
    counterElement.innerText = counter;
} */

// ====================Callback====================
/* // Тупо вкладываем одну функцию в другую
function checkTickets(message, success, fail) {
    setTimeout(() => {
        console.log('Ответ на предыдущем шаге:', message);
        console.log('Проверяем авиабилеты...');
        
        const availableTickets = true;

        if (availableTickets) {
            success('Билеты есть');
        } else {
            fail('Билеты нет');
        }
    }, 1000);
}

function checkRooms(success, fail){
    setTimeout(() => {
        console.log('Проверяем номера в отеле...');
        let availableRooms = true;

        if (availableRooms) {
            success('Номера есть');
        } else {
            fail('Номеров нет');
        }
    }, 1000);
}

function cancelVacation(message) {
    console.log('Ответ на предыдущем шаге:', message);
    console.log('Отпуск отменяется(');
}

function submitVacation(message) {
    console.log('Ответ на предыдущем шаге:', message);
    console.log('Едем в отпуск!');
}

checkRooms(
    (messageFromCheckRooms) => {
        checkTickets(
            messageFromCheckRooms,
            (messageFromCheckRooms) => {submitVacation(messageFromCheckRooms)},
            (messageFromCheckRooms) => {cancelVacation(messageFromCheckRooms)}
        )
    },
    (messageFromCheckRooms) => {cancelVacation(messageFromCheckRooms)}
); */

// ====================Промисы====================
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
