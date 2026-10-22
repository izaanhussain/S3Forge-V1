S3Forge-V1
A custom ESP32-S3 development-board design created in KiCad, with USB-C, GPIO expansion headers, reset/boot controls, indicator LEDs, and an onboard 3.3 V regulator.
<!-- Primary PCB visual: keep the clearest 3D board render immediately below the project title. -->
<p align="center">
  <img src="https://github.com/user-attachments/assets/93699a3c-aa6a-4ff9-98e4-4e2506a33964" alt="S3Forge-V1 ESP32-S3 development board 3D render" width="800" />
</p>
<p align="center"><em>Current KiCad design render — the board has not been presented as electrically validated or production-tested.</em></p>

S3Forge-V1 is a custom development-board project built around the ESP32-S3-WROOM-1 module. The design is intended to provide a compact platform for embedded experiments and prototypes, with USB-C connectivity, two GPIO expansion headers, reset and boot buttons, and power/user indicator LEDs.
Key specifications
Item	Design information
Main module	ESP32-S3-WROOM-1 (exact module variant should be confirmed before assembly)
PCB outline	70 mm × 55 mm, measured from the board Edge.Cuts rectangle in the KiCad PCB file
USB connector	USB-C receptacle; schematic includes USB D+ and D− nets
Intended input	5 V nominal from USB-C VBUS; verify the completed board and connector wiring before applying power
Regulator	AMS1117-3.3 linear regulator, intended to provide the 3.3 V rail
Expansion	Two 1×20, 2.54 mm-pitch header footprints
Controls	Reset and Boot push buttons
Indicators	Power LED and user LED
Design tools	KiCad PCB and schematic files are included
Firmware	No firmware/example sketch is included in this repository at present
Hardware status	Design files are provided; assembly, electrical validation, and USB/programming tests are not claimed here
Main features
ESP32-S3-WROOM-1 module footprint
USB-C connector with VBUS, ground, and USB D+/D− nets represented in the schematic
Two 20-pin GPIO expansion headers on 2.54 mm pitch
Reset and Boot buttons
Power and user LEDs
AMS1117-3.3 regulator and associated capacitors
Editable KiCad schematic and PCB layout
Production folder containing the BOM and Gerber archive
GPIO and expansion
The schematic labels the following module signals for the expansion design: IO1–IO18, IO21, and IO35–IO47. The two 1×20 header footprints provide the physical expansion points.
Use the schematic as the source of truth for the exact header-pin-to-signal mapping. Do not assume every labelled GPIO is suitable for every purpose: ESP32-S3 pins can have boot-strapping, USB, flash/PSRAM, or peripheral constraints depending on the exact module variant and circuit. Check the relevant ESP32-S3-WROOM-1 datasheet and verify the final PCB connectivity before attaching external hardware.
Power architecture
The intended power path is:
USB-C VBUS: nominal 5 V input from a USB power source.
AMS1117-3.3: linear regulator intended to step the input down to the board's 3.3 V rail.
3V3 rail: supplies the ESP32-S3 module and the board's low-voltage circuitry as drawn in the schematic.
Ground: USB-C ground and circuit ground form the board's common reference.
The schematic BOM lists two 10 µF capacitors, one 100 nF capacitor, and one 1 µF capacitor. Before powering a fabricated board, confirm the regulator pinout, capacitor placement and ratings, USB connector pin mapping, and regulator thermal/current limits against the exact components used. The AMS1117 is a linear regulator, so its temperature and usable current depend on input voltage, load, and PCB copper/thermal design.
USB functionality
The schematic contains a USB-C receptacle and USB D+ / D− signal nets intended to connect USB data to the ESP32-S3. The design also lists two 5.1 kΩ resistors, commonly used as USB-C sink/ device-side CC pull-downs; confirm their exact connections in the schematic before assembly.
This repository does not claim that USB data, power delivery, flashing, or serial output has been tested on a fabricated board. Before relying on USB for programming, check the connector's CC1/CC2, D+/D−, VBUS, and GND connections and verify continuity on the assembled PCB. No separate USB-to-UART bridge is listed in the BOM, so the intended programming/serial path is the ESP32-S3's native USB interface if the final wiring and firmware configuration support it.
PCB and schematic
Additional PCB views
<p align="center">
  <img src="https://github.com/user-attachments/assets/6b32a46a-7766-4dc9-9d2b-1cabbd1250ea" alt="S3Forge-V1 PCB layout view" width="800" />
</p>
<p align="center">
  <img src="https://github.com/user-attachments/assets/e5cee043-8714-4334-8a2e-543ebd4b36c3" alt="S3Forge-V1 additional PCB render" width="800" />
</p>
Schematic
<p align="center">
  <img src="https://github.com/user-attachments/assets/0e307d77-a813-4fa7-b6c7-76449a13279b" alt="S3Forge-V1 schematic overview" width="800" />
</p>
Bill of materials
The production BOM is available at `Production/BOM.csv`. The main listed parts are:
Reference / quantity	Part	Notes
U1 × 1	ESP32-S3-WROOM-1	Confirm the exact module variant before ordering
U2 × 1	AMS1117-3.3	Verify the selected part's pinout and thermal suitability
J1 × 1	USB-C receptacle	Confirm the exact footprint and pin mapping
J2, J3 × 2	1×20, 2.54 mm pin headers	Header style depends on assembly choice
SW1, SW2 × 2	Reset and Boot switches	Confirm footprint and switch availability
D1, D2 × 2	Power and user LEDs	Confirm LED colour and polarity
C1, C2 × 2	10 µF capacitors	Voltage rating/type should be selected for the circuit
C3 × 1	100 nF capacitor	Decoupling capacitor
C4 × 1	1 µF capacitor	Capacitor rating/type should be confirmed
R1, R2 × 2	10 kΩ resistors	—
R3, R4 × 2	5.1 kΩ resistors	Confirm CC-net connections in the schematic
R5 × 1	1 kΩ resistor	—
R6 × 1	330 Ω resistor	—
The BOM is a design-stage list, not a statement that parts have been purchased or assembled. Check all component footprints, ratings, and exact manufacturer part numbers before ordering or manufacturing.
Getting started
1. What you need
A fabricated and assembled S3Forge-V1 board
A known-good USB-C data cable (some USB-C cables are charge-only)
A computer with the required USB drivers, if your operating system needs them
Either the Arduino IDE with ESP32 board support or Espressif's ESP-IDF toolchain
This repository's KiCad files for checking the circuit and pin mapping
2. Inspect the design before powering it
Open `PCB/S3Forge-V1.kicad_pro` in KiCad.
Review `PCB/S3Forge-V1.kicad_sch` and `PCB/S3Forge-V1.kicad_pcb`.
Confirm USB-C connector orientation/pin mapping, regulator pinout, capacitor polarity where applicable, and the 3V3/GND nets.
If the board has been fabricated, check for solder bridges and verify that 5 V VBUS and 3.3 V rails are not shorted to ground before connecting USB.
3. Install a development toolchain
Option A — Arduino IDE
Install the Arduino IDE.
Install Espressif's esp32 board package using the Board Manager instructions in the official Arduino-ESP32 documentation.
Select an ESP32-S3 target compatible with the exact ESP32-S3-WROOM-1 module fitted to the board. If using the generic entry, choose ESP32S3 Dev Module only after confirming its configuration matches the hardware.
If using the ESP32-S3 native USB interface for upload or serial, enable the relevant USB CDC/USB mode options where the selected board package exposes them.
Option B — ESP-IDF
Install Espressif's ESP-IDF using the official ESP-IDF installation guide for your operating system.
Open an ESP-IDF terminal and configure a project for the ESP32-S3 target (`esp32s3`).
Configure the port and USB/serial settings to match the board's actual hardware connection.
4. Connect the board and identify the port
Connect the assembled board to your computer with a USB-C data cable.
Check Device Manager on Windows, or the available serial devices on Linux/macOS, for a newly detected USB/serial device.
If no device appears, disconnect power and re-check the USB-C wiring, cable, soldering, and native USB configuration. The design has not yet been verified as a working assembled board, so detection cannot be guaranteed.
5. Flash a sample program
Firmware availability: this repository currently contains hardware design files only; it does not include a tested firmware project or a ready-to-flash binary.
For a first test, create a minimal Arduino sketch or ESP-IDF example for the ESP32-S3. Select the matching target and detected port, then upload using the toolchain's normal upload command. A basic serial-print example is a safer first test than connecting peripherals to unverified GPIOs. If upload fails, check the board's Boot/Reset controls and confirm the native USB wiring and boot mode against the ESP32-S3 documentation.
6. View serial output
Open the Arduino IDE Serial Monitor or an ESP-IDF serial monitor.
Select the detected port and use the baud rate configured in your sample program (for example, 115200 baud for a typical UART-style example).
Reset the board and look for the sample program's output.
Serial output depends on the chosen interface and firmware configuration. Native USB CDC output and UART output are not interchangeable; confirm which interface the example uses and how it is routed on the assembled board.
Repository structure
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
Design files and manufacturing
KiCad source: `PCB/`
Production copy of design files: `Production/`
Bill of materials: `Production/BOM.csv`
Gerber archive: `Production/gerbers.zip`
Review the Gerbers in a Gerber viewer and confirm board outline, copper layers, drill files, and manufacturing rules before sending them to a PCB manufacturer. The production files are supplied for review; manufacturing and electrical testing are not implied.
Current status and limitations
KiCad schematic and PCB layout are included.
A BOM and Gerber archive are included.
Firmware/example code is not currently included.
No claim is made that a fabricated board has passed power-on, USB enumeration, flashing, GPIO, or thermal tests.
Confirm exact module variant, footprints, regulator suitability, USB wiring, and GPIO mapping before fabrication or use.
License
See `LICENSE` for the project's license.
