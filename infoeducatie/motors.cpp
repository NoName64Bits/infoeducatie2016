#include "motors.h"

Config mcf;

Motors::Motors(){

}

void Motors::set(int s1, int s2){
  (this -> s1) = s1;
  (this -> s2) = s2;
}

int Motors::get(int id){
  if(id == 0) return (this -> s1);
  return (this -> s2);
}

void Motors::update(){
  int sLeft = (this -> s1);
  int sRight = (this -> s2);

  //left motor
  if(sLeft < 0){
    digitalWrite(mcf._motors[0], false);
    analogWrite(mcf._motors[1], -sLeft);
  } else if(sLeft > 0){
    digitalWrite(mcf._motors[1], false);
    analogWrite(mcf._motors[0], sLeft);
  } else if(sLeft == 0){
    digitalWrite(mcf._motors[0], false);
    digitalWrite(mcf._motors[1], false);
  }

  //right motor:
  if(sRight < 0){
    digitalWrite(mcf._motors[2], false);
    analogWrite(mcf._motors[3], -sRight);
  } else if(sRight > 0){
    digitalWrite(mcf._motors[3], false);
    analogWrite(mcf._motors[2], sRight);
  } else if(sRight == 0){
    digitalWrite(mcf._motors[2], false);
    digitalWrite(mcf._motors[3], false);
  }
}

void Motors::move(int s1, int s2){
  (this -> set)(s1, s2);
  (this -> update)();
}

void Motors::set(Speed s){
  (this -> set)(s.getMotorSpeed(0), s.getMotorSpeed(1));
}

void Motors::move(Speed s){
  (this -> move)(s.getMotorSpeed(0), s.getMotorSpeed(1));
}
