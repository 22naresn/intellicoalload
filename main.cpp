// main.cpp
#include <SPI.h>
#include <LoRa.h>
#include <SoftwareSerial.h>
#include "fetch_weight.h"

// Define pins for LoRa module
#define LORA_SS 5
#define LORA_RST 16
#define LORA_DIO0 4

// Define pins for laser displacement sensor
#define LASER_RX 14
#define LASER_TX 12

// Initialize SoftwareSerial for laser sensor
SoftwareSerial laserSerial(LASER_RX, LASER_TX);

// LoRa settings
const int LORA_FREQUENCY = 866E6; // Frequency in Hz
const int LORA_SF = 7; // Spreading Factor
const int LORA_TX_POWER = 17; // TX Power in dBm

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
  laserSerial.begin(9600);

  // Initialize LoRa module
  SPI.begin(14, 12, 13, 5);
  LoRa.setPins(LORA_SS, LORA_RST, LORA_DIO0);
  if (!LoRa.begin(LORA_FREQUENCY)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  LoRa.setSpreadingFactor(LORA_SF);
  LoRa.setTxPower(LORA_TX_POWER);

  // Initialize laser displacement sensor
  laserSerial.write("INIT\n");
  delay(100);
}

void loop() {
  // Fetch weight using the fetch_weight module
  float weight = fetchWeight();

  // Send weight data via LoRa
  sendLoRaData(weight);

  // Delay for next reading
  delay(1000);
}

void sendLoRaData(float weight) {
  LoRa.beginPacket();
  LoRa.print("Weight:");
  LoRa.print(weight);
  LoRa.endPacket();
  Serial.println("Data sent via LoRa");
}