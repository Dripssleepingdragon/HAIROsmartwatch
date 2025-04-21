String analisisOfflineEmosi(int detak, int suhu) {
  if (detak > 110 && suhu > 38) return "Kurang sehat bro, masa depan masih panjang, kita rehat sejenak!.";
  else if (detak > 90) return "Bro? kamu lagi cemas ya? apa lagi aktif nih bun?.";
  else if (detak < 70) return "Lagi santai kah bro, chill dulu gak sih? mau ngobrol ngobrol juga boleh.";
  return "Kondisimu normal dan stabil.";
}