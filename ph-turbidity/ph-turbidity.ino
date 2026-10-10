#define PH_PIN 33
#define TURBIDITY_PIN 32

const float ADC_REFERENCE = 3.3;
const float ADC_STEPS = 4095.0;
const float PH_SLOPE = 1.75;
const float PH_OFFSET = 6.5;
const unsigned long READ_DELAY_MS = 2000;

float readVoltage(int pin) {
    return analogRead(pin) * ADC_REFERENCE / ADC_STEPS;
}

float readPh() {
    return constrain(readVoltage(PH_PIN) * PH_SLOPE + PH_OFFSET, 0.0f, 14.0f);
}

float readTurbidity() {
    return max((ADC_REFERENCE - readVoltage(TURBIDITY_PIN)) * 2.0f, 0.0f);
}

void setup() {
    Serial.begin(115200);
    analogReadResolution(12);
}

void loop() {
    Serial.print("pH: ");
    Serial.print(readPh(), 2);
    Serial.print(" | Turbidity: ");
    Serial.print(readTurbidity(), 2);
    Serial.println(" NTU");

    delay(READ_DELAY_MS);
}
