#include <avr/io.h>
#include "PWM.h"

void PWM_init(){
  TCCR2A = TCCR2A | (1<<0) | (1<<1);   // Setting WGM01 and WGM00 
  TCCR2B = TCCR2B &~ (1<<3);           // Clearing WGM02

  TCCR2B = TCCR2B | (1<<CS02);         // Setting CS02
  TCCR2B = TCCR2B &~ (1<<CS00);        // Clearing CS01
  TCCR2B = TCCR2B &~ (1<<CS01);        // Clearing CS00

  TCCR2A = TCCR2A | (1<<7);            // Setting COM0A1
  TCCR2A = TCCR2A &~ (1<<6);           // Clearing COM0A0

  DDRB |= (1<<3);
   
}


void Set_DutyCycle(int duty){

  OCR2A = (256*duty / 100)-1;
}
