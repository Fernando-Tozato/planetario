String comando;

void setup() {
    Serial.begin(9600);
}

void loop() {
    if (Serial.available()) {
        comando = Serial.readString();
    }
}