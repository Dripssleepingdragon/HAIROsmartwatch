String userInput = "suhu tubuhku bagaimana?"; // Simulasi input suara → teks
String response = getLocalResponse(userInput, heartRate, suhu);
Serial.println("Hairo [offline]: " + response);