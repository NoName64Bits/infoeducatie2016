#include "sensors.h"
#include "config.h"
#include "QTRSensors.h"

Config scf;

SensorQuery::SensorQuery(int top, int front, int right){
  this -> top = top;
  this -> front = front;
  this -> right = right;
}

bool SensorQuery::getQueryData(int index){
  if(index == TOP){
    return this -> topRes;
  } else if(index == FRONT) {
    return this -> frontRes;
  } else if(index == RIGHT){
    return this -> rightRes;
  }
}

Sensors::Sensors(){

}

SensorQuery Sensors::executeQuery(SensorQuery sq){
  for(int i = 0; i < 3; i++){
    if(i == TOP && sq.top >= 0){
        if(map(analogRead(scf._irSensors[TOP]), 0, 1024, 0, 255) > sq.top){
          sq.topRes = true;
        } else {
          sq.topRes = false;
        }
    } else if(i == FRONT && sq.front >= 0){
      if(analogRead(scf._irSensors[FRONT]) > sq.front){
        sq.frontRes = true;
      } else {
        sq.frontRes = false;
      }
    } else if(i == RIGHT && sq.right >= 0){
      sq.rightRes = !digitalRead(scf._irSensors[RIGHT]);
    }
  }

  return sq;
}

#define NUM_SENSORS             6
#define NUM_SAMPLES_PER_SENSOR  4

QTRSensorsAnalog qtra((unsigned char[]) {A5, A4, A3, A2, A1, A0}, NUM_SENSORS, NUM_SAMPLES_PER_SENSOR);
unsigned int sensorValues[NUM_SENSORS];

Line::Line(){

}

void Line::calibrate(int x){
  for (int i = 0; i < x; i++)
  {
    qtra.calibrate();
  }
}

int Line::getPosition(){
  return qtra.readLine(sensorValues);
}
