

#include <arduino.h>

const int IR_L = 5;
const int IR_R = 6;
  
char currentStatusOfPin     = 0;
char previousStatusOfPin    = 0;

#define NOTHING  0xFF

void setup() 
{
  Serial.begin(19200);

  pinMode(IR_L,   INPUT);
  pinMode(IR_R,   INPUT);

}

char pin_status_left()
{
    //0x01 and 0XFE - first bit of variable for first pin
    currentStatusOfPin = digitalRead(IR_L) ? currentStatusOfPin,1 | 0x01 : currentStatusOfPin & 0xFE;


    return ((currentStatusOfPin ^ previousStatusOfPin) & 0x01) ? previousStatusOfPin = currentStatusOfPin,
                                                        currentStatusOfPin & 0x01: NOTHING;

    // if((currentStatusOfPin ^ previousStatusOfPin) & 0x01)
    // {
    //     previousStatusOfPin = currentStatusOfPin;
    //     return currentStatusOfPin & 0x01;
    // } 
    // else
    //     return NOTHING;
}

char pin_status_right()
{
     //0x02 and 0XFD - first bit of variable for first pin
    currentStatusOfPin = digitalRead(IR_R) ? currentStatusOfPin | 0x02 : currentStatusOfPin & 0xFD;

    return ((currentStatusOfPin ^ previousStatusOfPin) & 0x02) ? previousStatusOfPin = currentStatusOfPin,
                                                        currentStatusOfPin & 0x02: NOTHING;

    // if((currentStatusOfPin ^ previousStatusOfPin) & 0x02)
    // {
    //     previousStatusOfPin = currentStatusOfPin;
    //     return currentStatusOfPin & 0x2;
    // } 
    // else
    //     return NOTHING;
}


void loop() 
{
    

}
