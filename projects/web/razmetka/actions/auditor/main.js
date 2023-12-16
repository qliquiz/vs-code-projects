let table = document.getElementById('table');
let cells = table.getElementsByTagName('td');

function randomColor() {
    let r = Math.floor(Math.random() * 256);
    let g = Math.floor(Math.random() * 256);
    let b = Math.floor(Math.random() * 256);
    
    return 'rgb(' + r + ',' + g + ',' + b + ')';
}

function colorCell(event) {
    event.target.style.backgroundColor = randomColor();
}

for (let i = 0; i < cells.length; i++) {
    cells[i].addEventListener('click', colorCell);
    cells[i].setAttribute('width', '100px');
}
