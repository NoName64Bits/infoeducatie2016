#include <Arduino.h>
#include "speed.h"

class PIDController{
  public:
    PIDController();
    PIDController(float p, float i, float d);
    void setConstants(float p, float i, float d);
    void setIntegralMode(int iMode);
    void setMaxSpeed(int maxSpeed);
    void setTresh(int tresh);
    int getError(int position);
    Speed drive(int error);
    ~PIDController();

  private:
    float p, i, d;
    int iMode = 0;
    int maxSpeed = 120;
    int lastProportional = 0;
    int tresh = 10000;
    int integral = 0;
};
