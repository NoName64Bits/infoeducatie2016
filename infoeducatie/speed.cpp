#include "speed.h"

Speed::Speed(int m1, int m2){
  (this -> s1) = m1;
  (this -> s2) = m2;
}

int Speed::getMotorSpeed(int id){
  if(id == 0) return (this -> s1);
  return (this -> s2);
}

void Speed::setMotorSpeed(int id, int val){
  if(id == 0) (this -> s1) = val;
  (this -> s2) = val;
}
