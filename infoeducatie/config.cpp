#include "config.h"

Config::Config(){
}

void Config::init(){
  for(int i = 0; i < 4; i++){
    pinMode((this -> _motors)[i], OUTPUT);
  }
  pinMode((this -> _servoPin), OUTPUT);
  for(int i = 0; i < 3; i++){
    pinMode(_irSensors[i], INPUT);
  }
  pinMode(_led, OUTPUT);
  pinMode(_switch, OUTPUT);
}
