#ifndef config_infoeducatie
#define config_infoeducatie

#include <Arduino.h>

#define TOP 0
#define FRONT 1
#define RIGHT  2

class Config{
  public:
    Config();
    void init();
    int _motors[4] = {5, 3, 11, 6};
    int _servoPin = 9;
    int _irSensors[3] = {A8, A10, 12};
    int _led = 7; 
    int _switch = 2;
  };

#endif
