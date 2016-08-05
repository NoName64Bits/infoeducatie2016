#include "arm.h"
#include "config.h"

Config acf;

Arm::Arm(){ }

void Arm::init(){
  (this -> _arm).attach(acf._servoPin);
}

void Arm::setLimits(int low, int high){
  (this -> lowLimit) = low;
  (this -> highLimit) = high;
}

void Arm::set(int x){
  (this -> _arm).write(x);
}

void Arm::shoot(int d){
  (this -> _arm).write((this -> lowLimit));
  delay(d);
  (this -> _arm).write((this -> highLimit));
  delay(d);
}

void Arm::reset(){
  (this -> _arm).write((this -> highLimit));
}
