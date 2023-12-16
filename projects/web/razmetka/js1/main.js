const inputText = document.querySelector('#input-text');
const textBlock = document.querySelector('#text-block');
const button = document.querySelector('#button');

button.onclick = (e) => {
    e.preventDefault();
    textBlock.innerText = calmize(inputText.value);
    inputText.value = '';
    inputText.focus();
}

function calmize(str) {
    let processedText = '';
    let convertNextChar = false;

    for (let i = 0; i < str.length; i++) {
        if (str[i] === '-') convertNextChar = true;
        else if (convertNextChar) {
            processedText += str[i].toUpperCase();
            convertNextChar = false;
        } else processedText += str[i];
    }

    return processedText;
}
