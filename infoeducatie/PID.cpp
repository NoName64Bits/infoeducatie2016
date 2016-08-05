#include "PID.h"

PIDController::PIDController(){ }

PIDController::PIDController(float p, float i, float d){
  this -> p = p;
  this -> i = i;
  this -> d = d;
}

void PIDController::setConstants(float p, float i, float d){
  this -> p = p;
  this -> i = i;
  this -> d = d;
}

void PIDController::setTresh(int tresh){
  this -> tresh = tresh;
}

void PIDController::setIntegralMode(int iMode){
  this -> iMode = iMode;
}

void PIDController::setMaxSpeed(int maxSpeed){
  this -> maxSpeed = maxSpeed;
}

int PIDController::getError(int position){
  //int center = ((count * 1000) / 2);
  int center = 2500;

  if(this -> integral > this -> tresh) this -> integral = 0;

  int proportional = position - center;
  int derivativ =  proportional - this -> lastProportional;
  this -> integral += proportional;
  this -> lastProportional = proportional;

  int error = proportional / this -> p + derivativ * this -> d + (this -> iMode * (this -> integral / this -> i));

  return error;
}

Speed PIDController::drive(int error){
  if(error > this -> maxSpeed){
    error = this -> maxSpeed;
  }

  if(error < -(this -> maxSpeed)){
    error = -(this -> maxSpeed);
  }

  Speed sReturn(0, 0);

  if(error < 0){
    sReturn.setMotorSpeed(0, error);
    sReturn.setMotorSpeed(1, (this -> maxSpeed) + error);
  } else {
    sReturn.setMotorSpeed(0, (this -> maxSpeed) - error);
    sReturn.setMotorSpeed(1, error);
  }

  return sReturn;
}

PIDController::~PIDController(){ }
