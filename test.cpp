// test.cpp
#include <SoftwareSerial.h>

// Define pins for laser displacement sensor
#define LASER_RX 14
#define LASER_TX 12

// Initialize SoftwareSerial for laser sensor
SoftwareSerial laserSerial(LASER_RX, LASER_TX);

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
  laserSerial.begin(9600);

  // Initialize laser displacement sensor
  laserSerial.write("INIT\n");
  delay(100);
}

void loop() {
  // Send measurement command to laser sensor
  laserSerial.write("MEASURE\n");
  delay(100);

  // Read displacement from laser sensor
  if (laserSerial.available()) {
    float displacement = laserSerial.parseFloat();
    Serial.print("Displacement: ");
    Serial.println(displacement);
  }

  // Delay for next reading
  delay(1000);
}