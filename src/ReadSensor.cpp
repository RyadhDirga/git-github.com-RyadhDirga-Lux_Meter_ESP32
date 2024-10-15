#include "dev_Config.h"
#include "RTCHandler.h"
#include "LoRaHandler.h"
#include "ReadSensor.h"

ReadSensor::ReadSensor(){}

void ReadSensor::begin()
{
    Serial.begin(115200);
    Serial2.begin(9600);
}

void ReadSensor::Read()
{
    Serial2.write('D');
}

float ReadSensor::readSensorData()
{
    ReadSensor.Read();
    delay(2000);
    if(Serial2.available())
    {
        String response = Serial2.readStringUntil('\n');
        response trim();
        return response.toFloat();
        Serial.println(response);
        delay(10);
    }
    return 0.0;
}