
#include <Arduino.h>
#include "dev_Config.h"
#include "LoRaHandler.h"
#include "RTCHandler.h"
#include "ReadSensor.h"
#include "servoHandler.h"
 
void setup()
{
    RTCHandler.begin();
    LoRaHandler.begin();
    ReadSensor.begin();
    servoHandler.begin();
}

void loop()
{
    if(shouldMeasure)
    {
        servoHandler.move();
    }
    srv.write(90);
}