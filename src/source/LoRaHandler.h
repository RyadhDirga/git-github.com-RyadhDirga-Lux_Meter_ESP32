#include <Arduino.h>
#include <SPI.h>
#include <LoRa.h>
#include <LoRaWanPacket.h>

class LoRaHandler
{
public:
    void begin();
    void LoRa_setConfig(struct LoRa_config config);
    void LoRa_TxMode();
    void LoRa_SendMessage();
    void PayloadNow(stream &out);
    boolean runEvery(unsigned long interval);
private:
    struct LoRa_config
    {
    long Frequency;
    int SpreadingFactor;
    long SignalBandwidth;
    int CodingRate4;
    bool enableCrc;
    bool invertIQ;
    int SyncWord;
    int PreambleLength;
    };
    static LoRa_config txLoRa = {922000000, 7, 125000, 5, true, false, 0x34, 8};
    static unsigned long previousMillis;
    unsigned long currentMillis;      
};

