# S3Forge-V1

A custom ESP32-S3 development board that I designed in KiCad.

I want to make a small dev board with USB-C, some GPIO expansion, and onboard power management so that it's usable for real embedded projects.

## PCB

<img width="518" height="396" alt="image" src="https://github.com/user-attachments/assets/93699a3c-aa6a-4ff9-98e4-4e2506a33964" />

<img width="917" height="631" alt="image" src="https://github.com/user-attachments/assets/6b32a46a-7766-4dc9-9d2b-1cabbd1250ea" />

<img width="793" height="592" alt="image" src="https://github.com/user-attachments/assets/e5cee043-8714-4334-8a2e-543ebd4b36c3" />



## Features & hardware components

Main microcontroller: ESP32-S3-WROOM-1
USB-C connection
GPIO expansion headers
I²C, SPI and UART support through GPIO
Reset and Boot buttons
Power and user LEDs
AMS1117-3.3V regulator
Compact PCB layout in KiCad

## Schematic

<img width="575" height="399" alt="image" src="https://github.com/user-attachments/assets/0e307d77-a813-4fa7-b6c7-76449a13279b" />


## Bill of Materials

| Component | Part |
|---|---|
| Microcontroller module | ESP32-S3-WROOM-1 |
| USB connector | USB-C receptacle |
| Voltage regulator | AMS1117-3.3 |
| Buttons | Reset and Boot |
| LEDs | Power and user |
| Headers | 2.54 mm GPIO headers |
| Capacitors and resistors | SMD components |

## Design files

The PCB and schematic are being designed in KiCad. I have added the files in pcb folder and all other files including gerbers are in production folder.
