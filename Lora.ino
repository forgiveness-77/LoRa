#include <SPI.h>
#include <RH_RF95.h>

// Pin definitions (adjust if using different boards)
#define RFM95_CS 8
#define RFM95_RST 4
#define RFM95_INT 7

// LoRa frequency
#define RF95_FREQ 950.0

// LoRa driver instance
RH_RF95 rf95(RFM95_CS, RFM95_INT);
void setup() {
  pinMode(RFM95_RST, OUTPUT);
  digitalWrite(RFM95_RST, HIGH);
  Serial.begin(115200);
  while (!Serial) delay(1);
  // Manual reset of LoRa module
  digitalWrite(RFM95_RST, LOW);
  delay(10);
  digitalWrite(RFM95_RST, HIGH);
  delay(10);
  if (!rf95.init()) {
    Serial.println("LoRa radio init failed");
    while (1);
  }
  Serial.println("LoRa radio init OK!");
  if (!rf95.setFrequency(RF95_FREQ)) {
    Serial.println("setFrequency failed");
    while (1);
  }
  Serial.print("Set Freq to: ");
  Serial.println(RF95_FREQ);
  rf95.setTxPower(23, false);
  Serial.println("Ready to chat via LoRa!");
}


void loop() {
  // Receive
  if (rf95.available()) {
    uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
    uint8_t len = sizeof(buf);
    if (rf95.recv(buf, &len)) {
      buf[len] = '\0'; // Ensure null-terminated string
      Serial.print("[Friend]: ");
      Serial.println((char*)buf);
      Serial.print("RSSI: ");
      Serial.println(rf95.lastRssi(), DEC);
      Serial.println("***");
    }
  }

  
  // Send
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.trim();
    if (input.length() > 0) {
      rf95.send((uint8_t*)input.c_str(), input.length());
      rf95.waitPacketSent();
      Serial.print("[You]: ");
      Serial.println(input);
      Serial.println("***");
    }
  }
}