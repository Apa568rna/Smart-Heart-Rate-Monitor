# 💓 Smart Heart Rate Monitor

A compact Arduino-based system that uses the MAX30100 pulse oximeter sensor to monitor heart rate (bpm) and blood oxygen saturation (SpO₂), transmitting the data over Bluetooth using an HC-05 module.

## 📌 Features

- Real-time heart rate and SpO₂ monitoring  
- Beat detection with visual feedback via Serial Monitor  
- Bluetooth communication for wireless data transmission  
- Lightweight and efficient code for embedded applications

## 🧰 Hardware Requirements

- Arduino Uno/Nano  
- MAX30100 Pulse Oximeter Sensor  
- HC-05 Bluetooth Module  
- Jumper Wires  
- USB Cable

## 🔌 Circuit Connections

| MAX30100 Pin | Arduino Pin |
|--------------|-------------|
| VCC          | 3.3V        |
| GND          | GND         |
| SDA          | A4          |
| SCL          | A5          |

> 💡 Connect HC-05 TX to Arduino RX, and RX to Arduino TX (with voltage divider if needed).

## 📦 Library Used

- [`MAX30100_PulseOximeter`](https://github.com/oxullo/Arduino-MAX30100)  
  Install it via Arduino Library Manager or clone from GitHub.

## 🧠 Code Overview

- Initializes the MAX30100 sensor  
- Detects heartbeats and logs them  
- Sends heart rate and SpO₂ data every 1 second over Bluetooth

## 🚀 Getting Started

1. Connect your components as per the circuit.
2. Upload the code using Arduino IDE.
3. Open Serial Monitor (baud: 9600) or connect a Bluetooth terminal (e.g., Serial Bluetooth Terminal on Android).
4. View real-time readings.

## 📜 Sample Output

