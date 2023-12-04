document.getElementById('ul').addEventListener('click', function(event) {
    const childList = event.target.querySelector('ul');
    childList.classList.toggle('hidden');
});