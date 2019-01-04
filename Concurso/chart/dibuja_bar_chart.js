var ctx = document.getElementById("myChart");
var myChart = new Chart(ctx, {
    type: 'bar',
    data: {
        labels: algoritmos,
        datasets: [{
            label: 'Cantidad',
            data: cantidad,
            backgroundColor: [
                'rgba(28, 61, 255, 0.7)',
                'rgba(1, 36, 187, 0.7)',
                'rgba(9, 79, 164, 0.2)',
                'rgba(1, 134, 187, 0.2)',
                'rgba(1, 173, 177, 0.2)',
                'rgba(255, 255, 255, 1)',
                'rgba(1, 36, 187, 0.7)',
                'rgba(9, 79, 164, 0.2)',
                'rgba(255, 0, 0, 0.8)',
                'rgba(1, 134, 187, 0.2)',
                'rgba(1, 173, 177, 0.2)',
                'rgba(255, 255, 255, 0.2)'
            ],
            borderColor: [
                'rgba(28, 61, 255, 0.7)',
                'rgba(1, 36, 187, 0.7)',
                'rgba(9, 79, 164, 0.2)',
                'rgba(1, 134, 187, 0.2)',
                'rgba(1, 173, 177, 0.2)',
                'rgba(0, 0, 0, 0.3)',
                'rgba(1, 36, 187, 0.7)',
                'rgba(9, 79, 164, 0.2)',
                'rgba(255, 0, 0, 0.8)',
                'rgba(1, 134, 187, 0.2)',
                'rgba(1, 173, 177, 0.2)',
                'rgba(255, 255, 255, 1)'
            ],
            borderWidth: 1
        }]
    },
    options: {
        scales: {
            yAxes: [{
                ticks: {
                    beginAtZero: true
                }
            }]
        }
    }
});