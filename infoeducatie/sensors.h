#ifndef sens_infoeducatie
#define sens_infoeducatie

#include <Arduino.h>

class SensorQuery{
  public:
    SensorQuery(int top, int front, int right);
    bool getQueryData(int index);
    int top = false, front = false, right = false;
    bool topRes = false, frontRes = false, rightRes = false;
};

class Sensors{
  public:
    Sensors();
    SensorQuery executeQuery(SensorQuery sq);
};

class Line{
  public:
      Line();
      void calibrate(int x); //400 ~= 10 secs
      int getPosition();
};

#endif
