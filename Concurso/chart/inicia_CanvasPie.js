var canvas2 = document.getElementById("myChart2");
fitToContainer(canvas2);

function fitToContainer(canvas2) {
    canvas2.style.width = '100%';
    canvas2.style.height = '100%';
    canvas2.width = canvas2.offsetWidth;
    canvas2.height = canvas2.offsetHeight;
}