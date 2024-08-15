#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio1(22, 21);
RF24 radio2(16, 15);

void setup() {
  radio1.begin();
  radio2.begin();
  radio1.powerDown();
  radio2.powerDown();
  delay(1000);

  radio1.powerUp();
  radio1.setAutoAck(false);
  radio1.setPALevel(RF24_PA_HIGH);
  radio1.setDataRate(RF24_2MBPS);
  radio1.stopListening();
  radio1.setChannel(80);
  delay(1000);

  radio2.powerUp();
  radio2.setAutoAck(false);
  radio2.setPALevel(RF24_PA_HIGH);
  radio2.setDataRate(RF24_2MBPS);
  radio2.stopListening();
  radio2.setChannel(26);
  delay(1000);
}

void loop() {
  byte text = 255;
  radio1.setChannel(80);
  radio1.writeFast(&text, sizeof(text));
  radio2.setChannel(26);
  radio2.writeFast(&text, sizeof(text));
  radio1.setChannel(2);
  radio1.writeFast(&text, sizeof(text));
  radio2.setChannel(80);
  radio2.writeFast(&text, sizeof(text));
  radio1.setChannel(26);
  radio1.writeFast(&text, sizeof(text));
  radio2.setChannel(2);
  radio2.writeFast(&text, sizeof(text));
}
