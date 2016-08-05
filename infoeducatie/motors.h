#ifndef motors_infoeducatie
#define motors_infoeducatie

#include <Arduino.h>
#include "config.h"
#include "speed.h"

class Motors{
  public:
    Motors();
    void set(int s1, int s2);
    void set(Speed s);
    void move(int s1, int s2);
    void move(Speed s);
    int get(int id);
    void update();

  private:
    int s1 = 0, s2 = 0;
};

#endif
