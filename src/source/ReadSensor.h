#include <Arduino.h>

class ReadSensor()
{
public:
    void begin();
    void Read();
private:
    int lux;
    float readSensorData;
}