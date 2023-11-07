<img src="https://github.com/jrabinowitz2/DIY-Flash-Reader-SOIC16/blob/main/img/setup.png" >

# DIY Flash Reader: SOIC16
Instructions for building a homemade NAND flash chip reader/programmer for SOIC16 packages. Chip-on connection via "chip clip" with attached breakout; arduino-based microcontroller uses bit-banging to read from or program chip via Serial Peripheral Interface (SPI).

## Hardware
* Arduino-compatible microcontroller
* SOIC16 Clip + DIP Breakout
* Jumpers/wires
* Breadboard (optional)
  
## Software
* RDID.ino: reads out manufacturer ID code
* RDOTP.ino:
* FASTREAD.ino:

## Setup
### Hardware Setup
<img src="https://github.com/jrabinowitz2/DIY-Flash-Reader-SOIC16/blob/main/img/soic16_pinout.png" >

### Uploading code via Arduino
<img src="https://github.com/jrabinowitz2/DIY-Flash-Reader-SOIC16/blob/main/img/soic16_connections.png" >

### Running commands
<img src="https://github.com/jrabinowitz2/DIY-Flash-Reader-SOIC16/blob/main/img/soic16_running.png" >
