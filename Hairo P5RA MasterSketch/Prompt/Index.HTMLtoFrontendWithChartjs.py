<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Visualisasi Data Hairo</title>
  <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
</head>
<body>
  <h1>Visualisasi Data Hairo AI Smartwatch</h1>
  <canvas id="myChart" width="400" height="200"></canvas>

  <script>
    // Ambil data dari server
    fetch('/api/data')
      .then(response => response.json())
      .then(data => {
        const timestamps = data.map(item => item.timestamp);
        const heartRate = data.map(item => item.heartRate);
        const temperature = data.map(item => item.temperature);

        // Membuat chart
        const ctx = document.getElementById('myChart').getContext('2d');
        const myChart = new Chart(ctx, {
          type: 'line',
          data: {
            labels: timestamps,
            datasets: [{
              label: 'Detak Jantung',
              data: heartRate,
              borderColor: 'rgba(255, 99, 132, 1)',
              fill: false
            }, {
              label: 'Suhu',
              data: temperature,
              borderColor: 'rgba(54, 162, 235, 1)',
              fill: false
            }]
          }
        });
      });
  </script>
</body>
</html>
