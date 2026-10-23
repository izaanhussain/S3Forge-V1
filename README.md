
# S3Forge-V1

A custom ESP32-S3 development board designed in KiCad, featuring USB-C connectivity, GPIO expansion headers, reset and boot controls with indicator leds, and an onboard 3.3V regulator

<p align="center">
 <img width="678" height="460" alt="image" src="https://github.com/user-attachments/assets/d19b676d-e52a-4a1d-991c-edff30c422d0" />

<p align="center">
  <em> render </em>
</p>

the schematic PCB layout, bill of materials, and manufacturing files are included in the repository 

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
| Firmware | Test Firmware Included |


## Features

* ESP32-S3-WROOM-1 module footprint
* USB-C connector with USB D+ and D− signal nets
* Two 20-pin GPIO expansion headers
* Reset and Boot push buttons
* Power and user indicator LEDs
* Onboard AMS1117-3.3 voltage regulator
* Supporting capacitors and resistors
* Editable KiCad schematic and PCB layout
* Bill of materials and Gerber manufacturing archive


<p align="center">
 <img width="649" height="501" alt="Screenshot 2026-10-22 111045" src="https://github.com/user-attachments/assets/c5a1ed29-e515-4b11-8a02-f21711e54dc0" />
</p>


<p align="center">
  <img src="https://github.com/user-attachments/assets/e5cee043-8714-4334-8a2e-543ebd4b36c3" alt="S3Forge-V1 additional PCB render" width="800">
</p>

### Schematic

<p align="center">
  <img src="https://github.com/user-attachments/assets/0e307d77-a813-4fa7-b6c7-76449a13279b" alt="S3Forge-V1 circuit schematic" width="800">
</p>

## Extra Details

### 1. PCB 

the current PCB outline is approx **70 mm × 55 mm**
The board includes footprints for the ESP32-S3 module, USB-C connector, voltage regulator, supporting components, push buttons, indicator LEDs, and two expansion headers


### 2. GPIO Expansion

The schematic includes the following labelled ESP32-S3 signals:

* IO1–IO18
* IO21
* IO35–IO47
and Two 1×20 headers with 2.54 mm pitch

### 3. Power Architecture

the power architecture here is:

1). **USB-C VBUS:** Supplies 5V input
2). **AMS1117-3.3 regulator:** used to convert the input supply to 3.3V
3). **3.3V rail:** supplies the ESP32-S3 module and other low-voltage circuitry
4). **Ground:** Common ground pin

### 4. USB-C Functionality

the schematic contains a USB-C receptacle with VBUS, GND, D+, and D− signal nets

the programming approach is to use the ESP32-S3's native USB interface . provided the final wiring and firmware configuration support it. there is no separate usb to UART 


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

## getting Started

to use a an assembled S3Forge-V1 board, you'll need:-

1) An S3Forge-V1 PCB with components soldered 
2) A proper USB-C data cable
3) A computer running Windows or any other OS
4) arduino IDE or Espressif esp-idf
5) install the USB drivers if required by your OS

### Step 1: install Arduino IDE

1. install the Arduino IDE from the official Arduino website
2. open preferences and configure the Espressif ESP32 board package using the official installation instructions
3. open Boards Manger and install the ESP32 board package
4. select ESP32S3 Dev Module from Tools -> Board -> esp32

the upload settings are:-

1)USB CDC On Boot: Enabled
2)Upload Mode: Hardware CDC and JTAG
3)USB Mode: Hardware CDC and JTAG

select the COM port that appears when you connect the board and upload the firmware

Official resources you can checkout:-
- Arduino IDE: https://www.arduino.cc/en/software
- Arduino-ESP32 documentation: https://docs.espressif.com/projects/arduino-esp32/en/latest/

### Alternative: ESP-IDF

For development with Espressif's native framework:

1). install ESP-IDF using the official guide
2). create or open an ESP-IDF example project
3). set the target to `esp32s3`.
4). configure the correct serial or USB interface for the board

Official documentation: https://docs.espressif.com/projects/esp-idf/en/stable/esp32s3/get-started/

### Step 2: Connect the Board

after verifying the assembled hardware:--

1). connect the board to your computer using a USB-C data cable
2). check the available serial devices or Windows Device Manager
3). identify the port associated with the board

if the board is not detected check the cable  USB-C wiring soldering, and native USB config


### Step 3: Upload a Sample/test Program

A basic test firmware is available in the `Firmware` folder as `test_firmware.ino`

1). open the `test_firmware.ino` file in Arduino IDE
2). select the ESP32-S3 board from the boards menu
3). connect the board using a USB data cable and selct the correct port
4). click upload and wait for it to finish

set the baud rate to 115200 to check the output from the board

if the upload fails try pressing and holding the boot button while uploading and press Reset if needed

the firmware is just a basic test for now and the board should be checked properly before connecting other components to the GPIO pins, will release the proper specs and GPIO functions after i build it successfully 


### Step 4: View Serial Output

1). open the Arduino IDE Serial Monitor or an appropriate ESP-IDF monitor
2). select the correct port
3). set the baud rate to match the sample program which is 115200 baud rate
4). reset the board and check for output 

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
