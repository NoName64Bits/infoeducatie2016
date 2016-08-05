#ifndef arm_infoeducatie
#define arm_infoeducatie

#include <Arduino.h>
#include "Servo.h"

class Arm{
  public:
    Arm();
    void init();
    void setLimits(int low, int high);
    void shoot(int d);
    void reset();
    void set(int x);
    Servo _arm;
    int lowLimit = 5, highLimit = 175;
};

#endif
