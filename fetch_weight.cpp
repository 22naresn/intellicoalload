// fetch_weight.h
#ifndef FETCH_WEIGHT_H
#define FETCH_WEIGHT_H

float fetchWeight();

#endif

// fetch_weight.cpp
#include <SoftwareSerial.h>
#include "fetch_weight.h"

// Define pins for laser displacement sensor
#define LASER_RX 14
#define LASER_TX 12

// Initialize SoftwareSerial for laser sensor
extern SoftwareSerial laserSerial;

float fetchWeight() {
  float displacement = 0.0;
  float weight = 0.0;

  // Send measurement command to laser sensor
  laserSerial.write("MEASURE\n");
  delay(100);

  // Read displacement from laser sensor
  if (laserSerial.available()) {
    displacement = laserSerial.parseFloat();
    Serial.print("Displacement: ");
    Serial.println(displacement);
  }

  // Calculate weight based on displacement
  const float k = 10.0; // Calibration constant
  weight = k * displacement;
  Serial.print("Weight: ");
  Serial.println(weight);

  return weight;
}