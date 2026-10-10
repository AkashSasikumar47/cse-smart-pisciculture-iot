# Smart Pisciculture IoT

Water quality monitoring and automatic feeding for high-density fish farming, built with ESP8266 and ESP32 boards.

> Major project · Computer Science and Engineering, SRMIST · 2025
>
> Full title: IoT-integrated Water Quality Surveillance and Smart Feeding for High-Density Pisciculture Sustainability

## Features

- **Water quality:** measures TDS, temperature, pH and turbidity
- **Smart feeding:** a servo opens the feeder on a fixed cycle
- **Live readings:** every value is printed to the Serial Monitor

## Hardware

| Sketch            | Board             | Parts                                                                |
| ----------------- | ----------------- | -------------------------------------------------------------------- |
| `temp-tds-feeder` | NodeMCU (ESP8266) | TDS sensor on A0, DS18B20 temperature sensor on D1, SG90 servo on D2 |
| `ph-turbidity`    | ESP32             | pH sensor on GPIO 33, turbidity sensor on GPIO 32                    |

The DS18B20 needs a 4.7 kΩ pull-up resistor between its data line and 3.3 V.

## Built with

Arduino C++ with the ESP8266 and ESP32 Arduino cores, plus the `Servo`, `OneWire` and `DallasTemperature` libraries.

## Run it

1. Install the [Arduino IDE](https://www.arduino.cc/en/software) and add the ESP8266 and ESP32 boards in **Boards Manager**.
2. Install `OneWire` and `DallasTemperature` from **Library Manager**.
3. Open `temp-tds-feeder/temp-tds-feeder.ino`, pick **NodeMCU 1.0 (ESP-12E Module)** and upload it.
4. Open `ph-turbidity/ph-turbidity.ino`, pick **ESP32 Dev Module** and upload it.
5. Open the Serial Monitor at 115200 baud to see the readings.

## How it works

**`temp-tds-feeder`**, one cycle every 16 seconds:

1. Read the water temperature from the DS18B20.
2. Read the TDS sensor's voltage, correct it for temperature (2% per °C from 25 °C) and convert it to ppm.
3. Print both values, wait 5 seconds, then swing the feeder servo open and closed.

**`ph-turbidity`**, every 2 seconds:

1. Read both sensors with the ESP32's 12-bit ADC (0–3.3 V).
2. Convert the pH voltage with a linear calibration (`voltage × 1.75 + 6.5`), limited to 0–14.
3. Convert the turbidity voltage to NTU: the clearer the water, the higher the voltage.

## Project structure

```
temp-tds-feeder/   NodeMCU sketch: temperature, TDS and the feeder servo
ph-turbidity/      ESP32 sketch: pH and turbidity
```

## License

[MIT](LICENSE)
