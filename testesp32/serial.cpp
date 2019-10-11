#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "serial.h"
#include <inttypes.h>
#include <Stream.h>
#include <Arduino.h>

//Serial.begin(115200);
//Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);

void updateSerial()
{
  delay(500);
  while (Serial.available()) 
  {
    Serial2.write(Serial.read());//Forward what Serial received to Software Serial Port
    //Serial.println("1");
    //digitalWrite(19, HIGH);
  }
  while(Serial2.available()) 
  {
    Serial.write(Serial2.read());//Forward what Software Serial received to Serial Port
   // digitalWrite(18, HIGH);
   // Serial.println("2");
  }
}
