#include <Servo.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define TDS_PIN A0      // TDS sensor (Analog A0)
#define TEMP_PIN 5      // Temperature sensor (GPIO5 - D1)
#define SERVO_PIN 4     // Servo motor (GPIO4 - D2)

Servo feederServo;
OneWire oneWire(TEMP_PIN);
DallasTemperature sensors(&oneWire);

void setup() {
    Serial.begin(115200);
    feederServo.attach(SERVO_PIN);
    sensors.begin();
}

void loop() {
    // Read TDS sensor
    int tdsRaw = analogRead(TDS_PIN);
    float tdsValue = (tdsRaw / 1024.0) * 1000;  // Convert to ppm (approx.)

    // Read temperature sensor
    sensors.requestTemperatures();
    float temperature = sensors.getTempCByIndex(0);

    // Print sensor readings
    Serial.print("TDS Value: ");
    Serial.print(tdsValue);
    Serial.print(" ppm | Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");

    delay(5000);  // Wait 5 sec

    // Servo movement logic
    Serial.println("Servo Movement Start");

    feederServo.write(0);   // Move to 0°
    delay(500);
    feederServo.write(180); // Move to 180°
    delay(500);
    feederServo.write(0);   // Return to 0°
    
    Serial.println("Movement Complete");

    delay(10000);  // Wait 10 sec before repeating
}