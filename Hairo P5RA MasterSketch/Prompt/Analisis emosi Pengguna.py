int heartRate = analogRead(34);  // Sensor heart rate
int suhu = analogRead(35);       // Sensor suhu

String analisisEmosi(int detak, int suhu) {
  if (detak > 100 && suhu > 38) return "kamu tampak stres dan demam";
  else if (detak < 70) return "kamu tenang dan rileks";
  return "emosi normal";
}
