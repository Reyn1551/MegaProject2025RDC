// program esp32
#include "BluetoothSerial.h"

BluetoothSerial BT;

// UART2 untuk komunikasi ke Arduino Nano
HardwareSerial Nano(2);

void setup() {
  Serial.begin(115200);

  // Start Bluetooth
  BT.begin("ESP32-BT");
  Serial.println("Bluetooth ESP32 siap.");

  // UART ke Arduino Nano
  Nano.begin(9600, SERIAL_8N1, 16, 17); // RX=16, TX=17
}

void loop() {

  // Jika ada data masuk dari HP via Bluetooth
  if (BT.available()) {
    char incoming = BT.read();   // hanya satu karakter
    Serial.print("Dari HP: ");
    Serial.println(incoming);

    // Kirim 1 karakter ke Arduino Nano
    Nano.write(incoming);
  }

  // (opsional) Jika ada data dari Nano, kirim balik ke HP
  if (Nano.available()) {
    char fromNano = Nano.read();
    BT.write(fromNano);
  }
}