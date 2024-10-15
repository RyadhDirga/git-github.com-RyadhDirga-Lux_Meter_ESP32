#include <Arduino.h>
#include <Wire.h>
#include <RTClib.h>

class RTCHandler
{
public:
    RTCHandler();
    void begin();
    bool shouldMeasure();

private:
    RTC_DS3231 rtc;
    DateTime now;
    int currentHour;
    int currentMinute;
};