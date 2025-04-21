import streamlit as st
import pandas as pd
import json
import requests
import matplotlib.pyplot as plt

# Fungsi untuk mendapatkan data dari backend
def get_data():
    # Contoh endpoint yang bisa kamu ganti sesuai dengan API kamu
    url = "http://localhost:5000/api/data"
    response = requests.get(url)
    return response.json()

# Menampilkan DataFrame
st.title("Visualisasi Data Hairo AI Smartwatch")
data = get_data()
df = pd.DataFrame(data)

# Menampilkan Data
st.write(df)

# Visualisasi dengan plot
st.subheader("Grafik Detak Jantung vs Suhu")
fig, ax = plt.subplots()
ax.plot(df['timestamp'], df['heartRate'], label='Detak Jantung')
ax.plot(df['timestamp'], df['temperature'], label='Suhu')
ax.set_xlabel('Timestamp')
ax.set_ylabel('Nilai')
ax.legend()
st.pyplot(fig)
