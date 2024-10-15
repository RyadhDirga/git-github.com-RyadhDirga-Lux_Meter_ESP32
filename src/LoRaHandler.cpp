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

void LoRaHandler::LoRa_setConfig (struct LoRa_config config)
{
    LoRa.setFrequency(config.Frequency);
    LoRa.setSpreadingFactor(config.SpreadingFactor);
    LoRa.setSignalBandwidth(config.SignalBandwidth);
    LoRa.setCodingRate4(config.CodingRate4);

    if (config.enableCrc)
    LoRa.enableCrc();
    else 
    LoRa.disableCrc();
    if (config.invertIQ)
    LoRa.enableInvertIQ();
    else
    
    LoRa.disableInvertIQ();
    LoRa.setSyncWord(config.SyncWord);
    LoRa.setPreambleLength(config.PreambleLength);
}

void LoRaHandler::LoRa_TxMode()
{
    LoRa_setConfig(txLoRa);
    LoRa.idle();
}

void LoRaHandler::LoRa_SendMessage()
{
    LoRa_TxMode();
    LoRaWanPacket.clear();
    PayloadNow(LoRaWanPacket);
    
    if(LoRaWanPacket.encode())
    {
        LoRa.beginPacket();
        LoRa.write(LoRawanpacket.buffer(),LoRaWanpacket.length());
        LoRa.endPacket(true);
    }
}

void LoRaHandler::PayloadNow()
{
    out.print(json);
}

boolean LoRaHandler::runEvery(unsigned long interval)
{
    previousMillis = 0;
    currentMillis = millis();

    if (currentMillis - previousMillis >= interval)
    {
        previousMillis = currentMillis;
        return true;
    }
    return false;
}