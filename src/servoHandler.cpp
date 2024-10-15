#include "dev_Config"

servoHandler::servoHandler(){}

void servoHandler::begin()
{
    ESP32PWM::allocateTimer(0);
    ESP32PWM::allocateTimer(1);
    ESP32PWM::allocateTimer(2);
    ESP32PWM::allocateTimer(3);
    srv.setPeriodHertz(50);
    srv.attach(25, 500, 2400);
    srv.write(90);
}

void servoHandler::move()
{
    DynamicJsonDocument doc (2048);
    JsonArray lightArray = doc.createNestedArray("lux");

    for(int i = 0; i < numAngels; i++)
    {
        angle = angles[i];
        srv.write(angel);
        delay(1000);
        lux = readSensorData();
        lightArray.add(lux);
    }
    serializeJson(json);
    Serial.println(json);
    LoRa_sendMessage();
    
}