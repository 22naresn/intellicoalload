# Intellicoalload -- a Real-Time Load Monitoring System

This repository contains the code for a real-time load monitoring system for goods wagons.

## Project Structure

The project is divided into three main programs:

1. **main.cpp**: The main program that initializes the system, reads the displacement from the laser sensor, calculates the weight, and sends the data via LoRa.
2. **fetch_weight.cpp**: The module responsible for reading the displacement from the laser sensor and calculating the weight.
3. **test.cpp**: A test program to independently verify the functionality of the laser displacement sensor before deployment.

## Components

- **ESP32 Development Board**: ESP32-WROOM-32
- **LoRa Module**: SX1278
- **Laser Displacement Sensor**: LD20
- **Battery and Power Management Circuit**: LiPo 3.7V 2000mAh and TP4056
- **USB to Serial Converter**: CP2102

## Setup Instructions

### Hardware Setup

1. Connect the ESP32 to the LoRa module (SX1278) using the following pins:
   - ESP32 `D1(GPIO5)` to LoRa `SCK`
   - ESP32 `D7(GPIO13)` to LoRa `MISO`
   - ESP32 `D8(GPIO15)` to LoRa `MOSI`
   - ESP32 `D4(GPIO2)` to LoRa `CS`
   - ESP32 `D0(GPIO16)` to LoRa `RST`
   - ESP32 `D15(GPIO4)` to LoRa `DIO0`
   - ESP32 `3V3` to LoRa `VCC`
   - ESP32 `GND` to LoRa `GND`

2. Connect the ESP32 to the laser displacement sensor (LD20) using the following pins:
   - ESP32 `D5(GPIO14)` to Laser Sensor `RX`
   - ESP32 `D6(GPIO12)` to Laser Sensor `TX`
   - ESP32 `3V3` to Laser Sensor `VCC`
   - ESP32 `GND` to Laser Sensor `GND`

3. Connect the LiPo battery to the ESP32 and LoRa module using the TP4056 power management IC.

4. Place the entire setup inside the IP65 enclosure for weatherproofing.

### Software Setup

1. Install the Arduino IDE.
2. Install the ESP32 board manager in the Arduino IDE.
3. Install the LoRa library for Arduino.
4. Clone this repository and open the `main.cpp` file in the Arduino IDE.
5. Upload the code to the ESP32 development board.

### Running the Test Program

1. Open the `test.cpp` file in the Arduino IDE.
2. Upload the code to the ESP32 development board.
3. Open the Serial Monitor to view the displacement readings from the laser sensor.

## Usage

1. Power on the system.
2. The main program will initialize the ESP32, LoRa module, and laser displacement sensor.
3. The system will continuously read the displacement, calculate the weight, and send the data via LoRa.
4. The test program can be used to independently verify the functionality of the laser displacement sensor.

## Contributing

Contributions are welcome! Please open an issue or submit a pull request if you have any improvements or bug fixes.

## Contact

For any questions or issues, please contact [22naresn@gmail.com](mailto:22naresn@gmail.com).
