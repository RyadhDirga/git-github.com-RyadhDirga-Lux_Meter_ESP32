#include <Arduino.h>
#include <ESP32Servo.h>

class servoHandler
{
    public:
    void begin();
    void move();

    private:
    Servo srv;
    int angle;
}