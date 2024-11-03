# Major Project: IoT-integrated Water Quality Surveillance and Smart Feeding for High-Density Pisciculture Sustainability

## Overview
This project monitors water quality and automates fish feeding using IoT sensors and an ESP32 microcontroller.

## Features
- **Water Quality Monitoring:** Measures TDS, temperature, pH, and turbidity.
- **Smart Feeding:** Uses a servo motor for automated fish feeding.
- **Real-Time Data:** Displays sensor readings via Serial Monitor.

## Components
- **ESP32**
- **TDS Sensor**
- **DS18B20 Temperature Sensor**
- **pH Sensor**
- **Turbidity Sensor**
- **Servo Motor**

## Setup
1. Clone the repository:
   ```bash
   git clone https://github.com/AkashSasikumar47/Major-Project-IoT.git
   ```
2. Open the `.ino` file in **Arduino IDE**.
3. Install required libraries:
   - `Servo.h`
   - `OneWire.h`
   - `DallasTemperature.h`
4. Select the correct **board** and **COM port**.
5. Upload the code to ESP32.
6. Open Serial Monitor to view data.

## License
MIT License