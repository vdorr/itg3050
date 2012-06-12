
//June 12 2012
//This program is given to you without any warranty.
//The author disclaims copyright to this source code.

#include <Wire.h>
#include <stdint.h>
#include "itg3050.h"

#define GYRO_ADDR  I2C_ADDRESS_0

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  delay(100);
  Serial.println(itg3050_detect(GYRO_ADDR) ? "ITG-3050 not found :-(" :  "ITG-3050 found :-)");
}

void loop()
{}

int itg3050_detect(uint8_t i2c_addr)
{
  Wire.beginTransmission(i2c_addr);
  Wire.write((uint8_t)WHO_AM_I);
  Wire.endTransmission();
  Wire.requestFrom((uint8_t)i2c_addr, (uint8_t)1);
  if (Wire.available())
  { 
    uint8_t hello = Wire.read();
    return (hello & ID_MASK) != ID_VALUE;
  }
  return -1;

}
