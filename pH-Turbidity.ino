#define PH_PIN 33
#define TURBIDITY_PIN 32  

void setup() {
    Serial.begin(115200);
    pinMode(PH_PIN, INPUT);
    pinMode(TURBIDITY_PIN, INPUT);
}

void loop() {
    // Read and calculate pH value
    int phSensorValue = analogRead(PH_PIN);
    float phVoltage = phSensorValue * (3.3 / 4095.0);
    float phValue = (phVoltage * 1.75) + 6.5;
    phValue = constrain(phValue, 6.8, 7.5);

    // Read and calculate Turbidity in NTU
    int turbiditySensorValue = analogRead(TURBIDITY_PIN);
    float turbidityVoltage = turbiditySensorValue * (3.3 / 4095.0);
    float turbidityNTU = (((3.3 - turbidityVoltage) * 10) / 5);
    turbidityNTU = max(turbidityNTU, 0.0f);
    // Print the values
    Serial.print("pH Value: ");
    Serial.print(phValue, 2);
    Serial.print(" | Turbidity: ");
    Serial.print(turbidityNTU, 2);
    Serial.println(" NTU");

    delay(2000);
}