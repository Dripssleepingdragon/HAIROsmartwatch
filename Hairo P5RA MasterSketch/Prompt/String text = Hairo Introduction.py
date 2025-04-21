String text = "Assalamualaikum, gimana bro? Hairo disini!";
String url = "https://api.exampletts.com/speak?text=" + text;
HTTPClient http;
http.begin(url);
int httpCode = http.GET();
if (httpCode == 200) {
  // Play the MP3 file (butuh modul audio player)
}
