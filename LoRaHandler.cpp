#include "LoRaHandler.h"
#include "dev_Config.h"

LoRaHandler::LoRaHandler(){}

void LoRaHandler::begin()
{
    LoRaWanPacket.personalize(devAddr, nwkSKey, appSKey);
    LoRa.setPins(csPin, resetPin, irqPin);
    if (!LoRa.begin(txLoRa.Frequency))
    {
        Serial.println("LoRa init failed. Check your connections.");
        while (true);
    }
    Serial.println("LoRa init succeeded.");
    if (LoRaWanPacket.encode())
    {
        LoRa.beginPacket();
        LoRa.write(LoRaWanPacket.buffer(), LoRaWanPacket.length());
        LoRa.endPacket();
    }
}