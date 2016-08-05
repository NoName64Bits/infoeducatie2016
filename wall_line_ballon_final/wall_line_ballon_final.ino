#include <infoeducatie.h>

Config conf;
Motors motors;
Arm arm;
Sensors sensors;
Power power;

Line lin;
PIDController pid(1, 0, 0);

void setup() {
  //power.blinkLed(50, 250);
  Serial.begin(9600);
  initAll();
}

void initAll() {
  conf.init();
  arm.init();
  arm.setLimits(5, 160);
  arm.reset();

  while (!power.isActive());
  power.blinkLed(12, 250);
  power.setLed(true);

  pid.setMaxSpeed(255);

}

SensorQuery wallQuery(85, 75, 1);
SensorQuery ballQuery(95, -1, -1);

void loop() {
  //line();
  wall();
}

void line() {
  while (!power.isActive()) {
    int error = pid.getError(lin.getPosition());

    Serial.print(lin.getPosition());
    Serial.print(" - ");
    Serial.println(error);

    Speed s = pid.drive(error);
    motors.set(s);
    motors.update();
  }

  motors.move(0, 0);
  power.setLed(false);
}

void wall() {
  SensorQuery sqResults = sensors.executeQuery(wallQuery);

  if (digitalRead(2)) {
    if (!sqResults.getQueryData(FRONT)) {
      if (!sqResults.getQueryData(RIGHT)) {
        motors.set(210, -30);
      } else if (sqResults.getQueryData(RIGHT)) {
        motors.set(-30, 210);
      }
    } else {
      motors.move(-30, 210);
    }

    if (sqResults.getQueryData(TOP)) {
      motors.move(200, 200);
      arm.shoot(350);  
  }

    motors.update();
  } else
    motors.move(0, 0);
}
