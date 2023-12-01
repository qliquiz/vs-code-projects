let lis = document.querySelectorAll('li');

for (let li of lis){
    li.onclick = () => {
        let childList = li.querySelector('ul');
        childList.toggleAttribute('.hidden');
    }
}
/* document.getElementById('ul').addEventListener('click', function(event) {
    const target = event.target;
    if (target.tagName === 'li') {
        const childList = target.querySelector('ul');
        if (childList) {
            if (childList.style.display === 'none') {
                childList.style.display = 'block';
            } else {
                childList.style.display = 'none';
            }
        }
    }
});
 */