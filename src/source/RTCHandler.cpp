#include "dev_Config.h"
#include "RTCHandler.h"

RTCHandler::RTCHandler(){}

void RTCHandler::begin()
{
    if(!rtc.begin())
    {
        Serial.println("No RTC");
        while(1);
    }
    Serial.println("RTC Ok");
    if(rtc.lostPower())
    {
        Serial.println("Lost Power RTC");
        rtc.adjust(DateTime(F(__DATE__),F(__TIME__)));
    }
}

bool RTCHandler::shouldMeasure()
{
    now = rtc.now();
    currentHour = now.hour();
    currentMinute = now.minute();

    for (int time = 0; time < 3; time++)
    {
        if (currentHour == Times[time] && currentMinute < 5)
        {
            return true;
        }
    }
    return false;
}