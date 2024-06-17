#include "RF24.h"
#include "esp_bt.h"
#include "esp_wifi.h"

SPIClass *sp = nullptr;
RF24 radio(22, 21, 16000000);
byte i = 45;
unsigned int flag = 0;

void initSP() {
  sp = new SPIClass(VSPI);
  sp->begin();
  if (radio.begin(sp)) {
    delay(200);
    radio.setAutoAck(false);
    radio.stopListening();
    radio.setRetries(0, 0);
    radio.setPayloadSize(5);
    radio.setAddressWidth(3);
    radio.setPALevel(RF24_PA_MAX, true);
    radio.setDataRate(RF24_2MBPS);
    radio.setCRCLength(RF24_CRC_DISABLED);
    radio.startConstCarrier(RF24_PA_MAX, i);
  }
}

void setup() {
  esp_bt_controller_deinit();
  esp_wifi_stop();
  esp_wifi_deinit();
  initSP();
}

void loop() {
for (int i = 0; i < 79; i++) {
  radio.setChannel(i);
  }
}
