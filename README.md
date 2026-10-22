
# S3Forge-V1

A custom ESP32-S3 development board designed in KiCad, featuring USB-C connectivity, GPIO expansion headers, reset and boot controls, indicator LEDs, and an onboard 3.3V regulator.

<p align="center">
 <img width="678" height="460" alt="image" src="https://github.com/user-attachments/assets/d19b676d-e52a-4a1d-991c-edff30c422d0" />

<p align="center">
  <em> 3D render </em>
</p>

The board integrates USB-C connectivity, GPIO expansion headers, reset and boot buttons, indicator LEDs, and an onboard voltage regulator. The schematic, PCB layout, bill of materials, and manufacturing files are included in this repository.

## Specifications

| Specification | Details |
|---|---|
| Microcontroller module | ESP32-S3-WROOM-1 |
| PCB dimensions | 70 mm × 55 mm |
| USB connector | USB-C receptacle |
| Intended input voltage | 5V nominal via USB-C VBUS |
| Voltage regulator | AMS1117-3.3 |
| Logic voltage | 3.3V |
| GPIO expansion | Two 1×20 headers |
| Header pitch | 2.54 mm |
| Controls | Reset and Boot buttons |
| Indicators | Power LED and user LED |
| Design software | KiCad |
| Firmware | Not included yet |


## Features

- ESP32-S3-WROOM-1 module footprint
- USB-C connector with USB D+ and D− signal nets
- Two 20-pin GPIO expansion headers
- Reset and Boot push buttons
- Power and user indicator LEDs
- Onboard AMS1117-3.3 voltage regulator
- Supporting capacitors and resistors
- Editable KiCad schematic and PCB layout
- Bill of materials and Gerber manufacturing archive

## PCB Design

### PCB Layout

<p align="center">
 <img width="649" height="501" alt="Screenshot 2026-10-22 111045" src="https://github.com/user-attachments/assets/c5a1ed29-e515-4b11-8a02-f21711e54dc0" />
</p>

### Additional 3D View

<p align="center">
  <img src="https://github.com/user-attachments/assets/e5cee043-8714-4334-8a2e-543ebd4b36c3" alt="S3Forge-V1 additional PCB render" width="800">
</p>

### Schematic

<p align="center">
  <img src="https://github.com/user-attachments/assets/0e307d77-a813-4fa7-b6c7-76449a13279b" alt="S3Forge-V1 circuit schematic" width="800">
</p>

## Extra Details

### 1. PCB Dimensions

The current PCB outline measures approximately **70 mm × 55 mm**, based on the Edge.Cuts rectangle in the KiCad layout.

The board includes footprints for the ESP32-S3 module, USB-C connector, voltage regulator, supporting components, push buttons, indicator LEDs, and two expansion headers.

Check the final board outline, mounting requirements, and component clearances before manufacturing.

### 2. GPIO Expansion

The schematic includes the following labelled ESP32-S3 signals:

- IO1–IO18
- IO21
- IO35–IO47

Two 1×20 headers with 2.54 mm pitch provide physical expansion points.

### 3. Power Architecture

The intended power architecture is:

1. **USB-C VBUS:** Supplies nominal 5V input.
2. **AMS1117-3.3 regulator:** Intended to convert the input supply to 3.3V.
3. **3.3V rail:** Supplies the ESP32-S3 module and other low-voltage circuitry.
4. **Ground:** Provides a common electrical reference.

### 4. USB-C Functionality

The schematic contains a USB-C receptacle with VBUS, GND, D+, and D− signal nets.

The intended programming approach is to use the ESP32-S3's native USB interface, provided the final wiring and firmware configuration support it. No separate USB-to-UART bridge is listed.


## Bill of Materials

The complete BOM is available at [`Production/BOM.csv`](Production/BOM.csv).

| Reference | Component | Quantity |
|---|---|---:|
| U1 | ESP32-S3-WROOM-1 | 1 |
| U2 | AMS1117-3.3 regulator | 1 |
| J1 | USB-C receptacle | 1 |
| J2, J3 | 1×20 pin headers | 2 |
| SW1, SW2 | Reset and Boot switches | 2 |
| D1, D2 | Indicator LEDs | 2 |
| C1, C2 | 10 µF capacitors | 2 |
| C3 | 100 nF capacitor | 1 |
| C4 | 1 µF capacitor | 1 |
| R1, R2 | 10 kΩ resistors | 2 |
| R3, R4 | 5.1 kΩ resistors | 2 |
| R5 | 1 kΩ resistor | 1 |
| R6 | 330 Ω resistor | 1 |

## Getting Started

To use a fabricated and assembled S3Forge-V1 board, you will need:

- An S3Forge-V1 PCB with components assembled 
- A good USB-C data cable
- A computer running Windows or any other OS
- Arduino IDE or Espressif ESP-IDF
- USB drivers if required by your OS

### Step 1: Install Arduino IDE

1. Install the Arduino IDE from the official Arduino website.
2. Open Preferences and configure the Espressif ESP32 board package using the official installation instructions.
3. Open Boards Manager and install the ESP32 board package.
4. Select an ESP32-S3-compatible target.

The generic **ESP32S3 Dev Module** target may be suitable, but its configuration must match the exact module and hardware. Configure native USB options if required by the selected board package

Official resources:

- Arduino IDE: https://www.arduino.cc/en/software
- Arduino-ESP32 documentation: https://docs.espressif.com/projects/arduino-esp32/en/latest/

### Alternative: ESP-IDF

For development with Espressif's native framework:

1. Install ESP-IDF using the official guide
2. Create or open an ESP-IDF example project
3. Set the target to `esp32s3`.
4. Configure the correct serial or USB interface for the board

Official documentation: https://docs.espressif.com/projects/esp-idf/en/stable/esp32s3/get-started/

### Step 3: Connect the Board

After verifying the assembled hardware:

1. Connect the board to your computer using a USB-C data cable
2. Check the available serial devices or Windows Device Manager
3. Identify the port associated with the board

If the board is not detected check the cable  USB-C wiring soldering, and native USB configuration

### Step 4: Upload a Sample Program

A firmware example is not currently included in this repository.

To perform an initial test:

1. Create a minimal Arduino sketch or use an ESP32-S3 example.
2. Select the appropriate ESP32-S3 board target.
3. Select the detected upload port.
4. Upload the program using the IDE.

If upload fails, check the Boot and Reset controls and verify the hardware's USB connections and boot mode.

Avoid connecting peripherals to unverified GPIO pins until the pin mapping has been confirmed.

### Step 5: View Serial Output

1. Open the Arduino IDE Serial Monitor or an appropriate ESP-IDF monitor
2. Select the correct port
3. Set the baud rate to match the sample program. For a typical UART-style example, this may be 115200 baud rate
4. Reset the board and check for output 

Serial output depends on the interface used by the firmware. Native USB CDC and UART output are different interfaces, so confirm the selected configuration

## Repository Structure

```text
S3Forge-V1-main/
├── PCB/
│   ├── S3Forge-V1.kicad_pro
│   ├── S3Forge-V1.kicad_sch
│   └── S3Forge-V1.kicad_pcb
├── Production/
│   ├── BOM.csv
│   ├── gerbers.zip
│   ├── S3Forge-V1.kicad_pro
│   ├── S3Forge-V1.kicad_sch
│   └── S3Forge-V1.kicad_pcb
├── LICENSE
└── README.md
```

## Manufacturing Files

The `Production/` directory contains the BOM, Gerber archive, and copies of the KiCad design files.

## License

See [`LICENSE`](LICENSE) for the project's license.
