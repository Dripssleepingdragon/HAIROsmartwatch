const express = require("express");
const app = express();
const path = require("path");
const fs = require("fs");

// Endpoint untuk mendapatkan data (mock data)
app.get("/api/data", (req, res) => {
  const data = JSON.parse(fs.readFileSync("data_log.json", "utf-8"));
  res.json(data);
});

// Endpoint untuk menampilkan halaman HTML
app.get("/", (req, res) => {
  res.sendFile(path.join(__dirname, "index.html"));
});

app.listen(3000, () => {
  console.log("Server running on http://localhost:3000");
});
