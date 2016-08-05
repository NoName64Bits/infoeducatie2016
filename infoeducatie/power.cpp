#include "power.h"
#include "config.h"

Config pcf;

Power::Power(){

}

void Power::setLed(bool state){
  digitalWrite(pcf._led, state);
}

void Power::blinkLed(int time, int del){
  for(int i = 0; i < time; i++){
    digitalWrite(pcf._led, HIGH);
    delay(del);
    digitalWrite(pcf._led, LOW);
    delay(del);
  }
}

bool Power::isActive(){
  return digitalRead(pcf._switch);
}
