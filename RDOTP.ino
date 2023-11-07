#include <SPI.h>
#define RDOTP 0x4B
#define CLOCKRATE 85000000

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
  Serial.println("Initializating...");
  SPI.begin();
  pinMode(csPin, OUTPUT);
  pinMode(mosiPin, OUTPUT);
  pinMode(misoPin, INPUT);
  pinMode(clkPin, OUTPUT);
  delay(100);
  
  Serial.println("Beginning SPI Transaction...");
  SPI.beginTransaction(SPISettings(CLOCKRATE, MSBFIRST, SPI_MODE0));
  byte data;
  int counter;
  digitalWrite(csPin,LOW);
  
  transferAndWait(RDOTP);
  transferAndWait(0x00);
  transferAndWait(0x00);
  transferAndWait(0x00);

  for (counter=0; counter < 64; counter++){
    data = transferAndWait(0x00);
    Serial.print(data, HEX);
  }
  
  digitalWrite(csPin,HIGH);
  SPI.endTransaction();
  SPI.end();
}

void loop(){
}
