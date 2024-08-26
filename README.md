# Arduino XBee Tactical Data Link Project

## Overview
This project demonstrates the use of Arduino Uno boards with XBee modules to create a secure, wireless data link system. The system utilizes AES encryption and is designed to transmit sensor data, which controls an RGB LED based on the input received from multiple sensors.

## Features
- Secure data transmission using AES encryption.
- Real-time data processing and response.
- Wireless communication using XBee modules.
- Scalable and modular design with one coordinator and multiple router configurations.

## Hardware Requirements
- Arduino Uno boards (1 coordinator, 3 routers)
- XBee modules with shields
- RGB LED
- Analog sensors (e.g., potentiometers, light sensors)
- Connecting wires and breadboard

## Software Requirements
- Arduino IDE
- XBee Arduino library
- X-CTU (for programming the XBee modules)

## Setup Instructions
1. **Assemble Hardware**: Connect XBee shields to Arduino boards and set up the sensors and RGB LED on the breadboard.

![wiring diagram](https://github.com/gcoulby/ZigBeeEncryptedDataLink/blob/main/wiring-diagram.png?raw=true)

2. **Install Software**: Download and install the Arduino IDE, XBee Arduino library, and X-CTU from Digi's website.
3. **Configure XBee Modules using X-CTU**:
   - Set `PAN ID` to `17` for all modules to ensure they communicate on the same network (or any preferred ID, ensuring it is the same across all modules).
   - Set `JV (Join Verification)` to `1` on all routers to verify network addresses upon joining.
   - Set the `DH & DL (Destination Address)` to `0x0000` to enable broadcast messages.
   - Enable encryption by setting `EE (Encryption Enable)` to `1`.
   - Set the `KY (Encryption Key)` to `FB0CAD01` (or any preferred secure key, ensuring it is the same across all modules).
   - Ensure all modules are in `AT Mode` for simpler command and control setups.
4. **Upload Sketches**: Upload the router and coordinator sketches to the respective Arduino boards.
5. **Power On and Test**: Switch on the system and test connectivity and data flow across the modules.

## Usage
- Power on the system.
- The routers will read data from the attached sensors and send encrypted packets to the coordinator.
- The coordinator decrypts the packets, processes the sensor data, and controls the RGB LED based on the received values.

