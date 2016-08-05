#ifndef speed_info
#define speed_info

class Speed{
  public:
    Speed(int m1, int m2);
    int getMotorSpeed(int id);
    void setMotorSpeed(int id, int val);

  private:
    int s1, s2;
};

#endif
