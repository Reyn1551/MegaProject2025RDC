Program Arduino 

#define ledPin 13
int state = 0;

void setup() {
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, LOW);
    Serial.begin(9600);
}

void loop() {
    if (Serial.available() > 0) {
        state = Serial.read();  // baca satu karakter
    }

    if (state == '0') {
        digitalWrite(ledPin, LOW);
        state = 0; 
    }
    else if (state == '1') {
        digitalWrite(ledPin, HIGH);
        state = 0;
    }
}