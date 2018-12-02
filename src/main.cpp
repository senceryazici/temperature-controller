#include <Arduino.h>
#include "Temperature.h"


int val = 40;
int begin_time = 0;

void setup()
{
    Serial.begin(9600);
    begin_time = millis();
}



void loop()
{
    // if(Serial.available())
    // {
    //   val = Serial.parseInt();
    // }
    analogWrite(9, val);

    double temp = ReadThermistor(0, 35);

    Serial.print(millis()- begin_time);
    Serial.print("/");
    Serial.println(temp, 5);
    delay(500);
}
