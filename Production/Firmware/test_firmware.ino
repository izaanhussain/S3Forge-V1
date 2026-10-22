//This is a starter example, not proof that the PCB has been tested.

#include <Arduino.h>
#include <esp_system.h>

#define ENABLE_USER_LED 0
#define USER_LED_PIN    0

static unsigned long lastHeartbeat = 0;
static uint32_t bootCount = 0;

void setup() {
  Serial.begin(115200);

  // Give USB CDC serial time to connect; don't block startup forever.
  const unsigned long serialWaitStart = millis();
  while (!Serial && (millis() - serialWaitStart < 4000)) {
    delay(10);
  }

  Serial.println();
  Serial.println(F("================================"));
  Serial.println(F("       S3Forge-V1 Firmware"));
  Serial.println(F("       Basic Bring-Up Test"));
  Serial.println(F("================================"));

  Serial.printf("Chip model: %s\n", ESP.getChipModel().c_str());
  Serial.printf("Chip revision: %u\n", ESP.getChipRevision());
  Serial.printf("CPU frequency: %u MHz\n", ESP.getCpuFreqMHz());
  Serial.printf("Flash size: %u bytes\n", ESP.getFlashChipSize());
  Serial.printf("Free heap: %u bytes\n", ESP.getFreeHeap());
  Serial.printf("Reset reason: %d\n", (int)esp_reset_reason());

#if ENABLE_USER_LED
  pinMode(USER_LED_PIN, OUTPUT);
  digitalWrite(USER_LED_PIN, LOW);
  Serial.printf("User LED test enabled on GPIO %d.\n", USER_LED_PIN);
#else
  Serial.println(F("User LED test disabled; confirm its GPIO first."));
#endif

  Serial.println(F("If you can read this, serial output is working."));
  Serial.println(F("Heartbeat will print every 2 seconds."));
}

void loop() {
  const unsigned long now = millis();

  if (now - lastHeartbeat >= 2000) {
    lastHeartbeat = now;
    bootCount++;

    Serial.printf(
      "[S3Forge-V1] Heartbeat #%lu | Uptime: %lu s | Free heap: %u bytes\n",
      (unsigned long)bootCount,
      (unsigned long)(now / 1000),
      ESP.getFreeHeap()
    );

#if ENABLE_USER_LED
    digitalWrite(USER_LED_PIN, !digitalRead(USER_LED_PIN));
#endif
  }

  delay(10);
}
