
//June 12 2012
//This program is given to you without any warranty.
//The author disclaims copyright to this source code.

#include <Wire.h>
#include <stdint.h>
#include "itg3050.h"

#define GYRO_ADDR  ITG3050_I2C_ADDRESS_0

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  delay(100);
  Serial.println(itg3050_detect(GYRO_ADDR) ? "ITG-3050 not found :-(" :  "ITG-3050 found :-)");
  //itg3050_basic_setup(GYRO_ADDR);
  //itg3050_print_config(GYRO_ADDR);
}

void loop()
{
  delay(500);
  
  int16_t x, y, z;
  int rc = itg3050_read_all(GYRO_ADDR, &x, &y, &z);
  Serial.print("x= ");
  Serial.print(x);
  Serial.print(", y= ");
  Serial.print(y);
  Serial.print(", z= ");
  Serial.print(z);
  Serial.println("");
}

int itg3050_basic_setup(uint8_t i2c_addr)
{
  //DLPF_FS_SYNC
  return -1;
}

int itg3050_print_config(uint8_t i2c_addr)
{
  return -1;
}

int itg3050_read_all(uint8_t i2c_addr, int16_t* x, int16_t* y, int16_t* z)
{
  Wire.beginTransmission(i2c_addr);
  Wire.write((uint8_t)(ITG3050_GYRO_XOUT_H));
  Wire.endTransmission();
  Wire.requestFrom(i2c_addr, (uint8_t)6);

  uint8_t mem[6];
  for (int i = 0; (i < 6) && Wire.available(); i++)
  {
    mem[i^1] = Wire.read();//negate lsb to swap bytes in words
  }
  *x = ((int16_t*)mem)[0];
  *y = ((int16_t*)mem)[1];
  *z = ((int16_t*)mem)[2];
  return 0;
}

int itg3050_detect(uint8_t i2c_addr)
{
  Wire.beginTransmission(i2c_addr);
  Wire.write((uint8_t)ITG3050_WHO_AM_I);
  Wire.endTransmission();
  Wire.requestFrom((uint8_t)i2c_addr, (uint8_t)1);
  if (Wire.available())
  { 
    uint8_t hello = Wire.read();
    return (hello & ITG3050_ID_MASK) != ITG3050_ID_VALUE;
  }
  return -1;

}
