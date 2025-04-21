# 🧠 HAIRO – Smartwatch AI Asisten Pribadi

**Hairo** adalah prototipe *smartwatch berbasis AI* yang dirancang sebagai **asisten pribadi futuristik**. Proyek ini menggabungkan teknologi **IoT, Artificial Intelligence, biometrik, dan holografi** dalam satu perangkat wearable. Hairo mampu **menganalisis emosi, berinteraksi secara verbal, menampilkan informasi melalui hologram**, dan tetap responsif meski dalam kondisi offline.

---

## 🔧 Fitur Utama
- 🎙️ **Voice Interaction (STT + TTS)** – Komunikasi 2 arah antara pengguna dan AI
- 💓 **Sensor Biometrik** – Deteksi detak jantung, suhu, kelembapan, dan gerakan
- 📷 **Kamera + Object Detection** – Deteksi wajah dan benda secara lokal
- 🔐 **Fingerprint & Face Unlock** – Keamanan canggih berbasis biometrik
- 📡 **WiFi & Bluetooth Connectivity** – Sinkronisasi data ke cloud dan perangkat lain
- 🌐 **AI Character Engine** – Hairo mempelajari pengguna dan membentuk kepribadian unik
- 📍 **GPS + Gyro Navigation** – Pelacakan lokasi dan deteksi arah
- ⚡ **Offline Mode** – Tetap berfungsi dengan logika lokal saat tanpa internet
- 🧊 **Hologram Display** – Menampilkan informasi secara visual layaknya film sci-fi

---

## 🗂 Struktur Proyek
```
📁 ArduinoCode/
   └── hairo_ai.ino          # Sketch utama ESP32
📁 Backend/
   ├── server.js             # Server Node.js
   └── api.py                # (Opsional) API Flask untuk pengolahan AI lokal
📁 StreamlitDashboard/
   └── app.py                # Dashboard visualisasi data sensor real-time
📁 assets/
   └── schematic.png         # Skema sistem & wiring
📁 docs/
   └── pitch_deck.pdf        # Presentasi dan dokumentasi teknis
```

---

## 🚀 Getting Started
1. Clone repo: `git clone https://github.com/namakamu/hairo-smartwatch-ai.git`
2. Upload kode `ArduinoCode/hairo_ai.ino` ke ESP32-S3
3. Jalankan backend Node.js: `cd Backend && npm install && node server.js`
4. Buka dashboard Streamlit: `cd StreamlitDashboard && streamlit run app.py`

---

## 💬 Kontribusi
Silakan fork repo ini, buat fitur baru, atau laporkan bug via issue. Semua bentuk kontribusi sangat dihargai 🙌

---

## 📜 Lisensi
MIT License – bebas digunakan untuk pengembangan dan penelitian, dengan mencantumkan kredit pada pengembang asli.
