// Wire Slave Sender
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Sends data as an I2C/TWI slave device
// Refer to the "Wire Master Reader" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>
unsigned long IICfreetime = 0;
void setup()
{
  Wire.begin(2);                // join i2c bus with address #2
  Wire.onRequest(requestEvent); // register event
}

void loop()
{
  if (__HAL_I2C_GET_FLAG(Wire.getHandle(), I2C_FLAG_BUSY) == RESET) {
    IICfreetime = millis();                     //总线不忙
  } else if ((millis() - IICfreetime) > 100) {  //总线忙超过100ms复位
    Wire.end();
    Wire.begin(2);
    Wire.onRequest(requestEvent);
  }
  delay(1);
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent()
{
  Wire.write("hello "); // respond with message of 6 bytes
                       // as expected by master
}
