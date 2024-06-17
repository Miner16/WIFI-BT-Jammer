#include "RF24.h"
#include "esp_bt.h"
#include "esp_wifi.h"

SPIClass *hp = nullptr;
RF24 radio(16, 15, 16000000);
byte i = 45;
unsigned int flag = 0;

void setup(void) {
  esp_bt_controller_deinit();
  esp_wifi_stop();
  esp_wifi_deinit();
  hp = new SPIClass(HSPI);
  hp->begin();
  if (radio.begin(hp)) {
    delay(200);
    radio.setAutoAck(false);
    radio.stopListening();
    radio.setRetries(0, 0);
    radio.setPayloadSize(5);
    radio.setAddressWidth(3);
    radio.setPALevel(RF24_PA_MAX, true);
    radio.setDataRate(RF24_2MBPS);
    radio.setCRCLength(RF24_CRC_DISABLED);
    radio.printPrettyDetails();
    radio.startConstCarrier(RF24_PA_MAX, i);
  }
}

void loop() {
if (flag == 0) {
    i += 2;
  } else {
    i -= 2;
  }

  if ((i > 79) && (flag == 0)) {
    flag = 1;
  } else if ((i < 2) && (flag == 1)) {
    flag = 0;
  }

  radio.setChannel(i);
}
