document.getElementById('main-action-button').onclick = () => { document.getElementById('products').scrollIntoView({behavior: "smooth"}) }

let links = document.querySelectorAll('.menu-item > a');
for (let i = 0; i < links.length; i++) links[i].onclick = () => { document.getElementById(links[i].getAttribute('data-link')).scrollIntoView({behavior: "smooth"}) } 

let buttons = document.getElementsByClassName('product-button');
for (let i = 0; i < buttons.length; i++) buttons[i].onclick = () => { document.getElementById('order').scrollIntoView({behavior: "smooth"}) } 

let burger = document.getElementById('burger');
let name = document.getElementById('name');
let phone = document.getElementById('phone');
document.getElementById('order-action').onclick = () => {
    let hasError = false;

    [burger, name, phone].forEach(item => {
        if (!item.value) {
            item.parentElement.style.background = 'red';
            hasError = true;
        } else {
            item.parentElement.style.background = '';
        }
    });

    if (!hasError) {
        [burger, name, phone].forEach(item => { item.value = '' });
        alert('Спасибо за заказ! Мы скоро свяжемся с Вами)');
    }
}

/* document.getElementById('change-currency').onclick = (e) => {
    let currentCurrency = e.target.innerText;

    let newCurrency
} */