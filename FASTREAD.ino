#include <SPI.h>
#define FASTREAD 0x0B 
#define CLOCKRATE 108000000 
#define BYTECOUNT 67108864 
const int csPin = 10;
const int mosiPin = 11; 
const int misoPin = 12;
const int clkPin = 13;

byte transferAndWait (const byte what) 
{
  byte a = SPI.transfer (what); 
  delayMicroseconds (20); 
  return a;
}

void setup(){ 
  Serial.begin(9600); 
  SPI.begin(); pinMode(csPin, OUTPUT);
  pinMode(mosiPin, OUTPUT);
  pinMode(misoPin, INPUT);
  pinMode(clkPin, OUTPUT); 
  delay(100);

  SPI.beginTransaction(SPISettings(CLOCKRATE, MSBFIRST, SPI_MODE0));
  byte data;
  unsigned long int counter;

  digitalWrite(csPin,LOW);

  transferAndWait(FASTREAD);
  transferAndWait(0x00);
  transferAndWait(0x00);
  transferAndWait(0x00);
  transferAndWait(0x00);

  for(counter = 0; counter < BYTECOUNT; counter++){ 
    data = transferAndWait(0x00); 
    Serial.print(data, HEX);
  }
  digitalWrite(csPin,HIGH);
  SPI.endTransaction();
  SPI.end();
}

void loop(){
}
