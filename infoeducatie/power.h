#ifndef power_infoeducatie
#define power_infoeducatie

#include <Arduino.h>

class Power{
  public:
    Power();
    void setLed(bool state);
    void blinkLed(int time, int del);
    bool isActive();
};

#endif
