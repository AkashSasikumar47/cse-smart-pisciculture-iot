#include <Servo.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define TDS_PIN A0
#define TEMP_PIN D1
#define SERVO_PIN D2

const float ADC_REFERENCE = 3.3;
const float ADC_STEPS = 1024.0;
const unsigned long READ_DELAY_MS = 5000;
const unsigned long FEED_DELAY_MS = 10000;

Servo feederServo;
OneWire oneWire(TEMP_PIN);
DallasTemperature sensors(&oneWire);

float readTemperature() {
    sensors.requestTemperatures();
    return sensors.getTempCByIndex(0);
}

float readTds(float temperature) {
    float voltage = analogRead(TDS_PIN) * ADC_REFERENCE / ADC_STEPS;
    float compensated = voltage / (1.0 + 0.02 * (temperature - 25.0));
    return (133.42 * pow(compensated, 3) - 255.86 * pow(compensated, 2) + 857.39 * compensated) * 0.5;
}

void feed() {
    Serial.println("Feeding...");
    feederServo.write(180);
    delay(500);
    feederServo.write(0);
    delay(500);
    Serial.println("Feeding done");
}

void setup() {
    Serial.begin(115200);
    sensors.begin();
    feederServo.attach(SERVO_PIN);
    feederServo.write(0);
}

void loop() {
    float temperature = readTemperature();
    bool hasTemperature = temperature != DEVICE_DISCONNECTED_C;
    float tds = readTds(hasTemperature ? temperature : 25.0);

    Serial.print("TDS: ");
    Serial.print(tds, 0);
    Serial.print(" ppm | Temperature: ");
    if (hasTemperature) {
        Serial.print(temperature, 1);
        Serial.println(" °C");
    } else {
        Serial.println("sensor not found");
    }

    delay(READ_DELAY_MS);
    feed();
    delay(FEED_DELAY_MS);
}
