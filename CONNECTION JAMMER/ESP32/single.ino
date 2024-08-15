#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(22, 21);

void setup() {
  radio.begin();
  radio.powerDown();
  delay(1000);
  radio.powerUp();
  radio.setAutoAck(false);
  radio.setPALevel(RF24_PA_HIGH);
  radio.setDataRate(RF24_2MBPS);
  radio.stopListening();
  radio.setChannel(80);
  delay(1000);
}

void loop() {
  byte text = 255;
  radio.setChannel(80);
  radio.writeFast(&text, sizeof(text));
  radio.setChannel(26);
  radio.writeFast(&text, sizeof(text));
  radio.setChannel(2);
  radio.writeFast(&text, sizeof(text));
}
