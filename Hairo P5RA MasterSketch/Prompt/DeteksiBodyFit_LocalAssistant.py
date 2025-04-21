String getLocalResponse(String input, int heartRate, int suhu) {
  input.toLowerCase();

  if (input.indexOf("hai") >= 0  input.indexOf("halo") >= 0) {
    return "Hai! Ada yang bisa aku bantu?";
  } else if (input.indexOf("suhu") >= 0) {
    return "Suhu tubuhmu sekarang sekitar " + String(suhu) + " unit.";
  } else if (input.indexOf("detak") >= 0  input.indexOf("jantung") >= 0) {
    return "Detak jantungmu sekarang " + String(heartRate) + ".";
  } else if (input.indexOf("kabar") >= 0 || input.indexOf("bagaimana") >= 0) {
    if (heartRate > 100 && suhu > 38) return "Udah kurang fit nih, kayaknya lagi stress & demam, turu bro.";
    else return "Alhamdulillah aman, body fit sehat segar ya bun? aamiin.";
  } else {
    return "Maaflah, aku aku tak paham loh, pake bahasa lain boleh?.";
  }
}