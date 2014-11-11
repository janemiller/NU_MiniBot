#ifndef MINI_BOT_H
#define MINI_BOT_H

#include <Arduino.h>
#include <avr/power.h>

namespace nurc {

enum Timer {
  TIMER_0,
  TIMER_1,
  NUM_TIMERS
};

enum Direction {
  BACKWARD,
  FORWARD
};

class Servo {
public:
  Servo(int timer_id = TIMER_0);
  ~Servo();
  
  int duty_cycle_;
  void setAngle(int angle);
private:
  Timer timer_;
  int bottom_count_;
  int top_count_;
  int angle_;
};

class Motor {
public:
  Motor(int pin);
  ~Motor();
  
  void driving(bool state);
  void changeDirection(Direction d);
private:
  int drive_pin_;
  int direction_pin_;
  bool inverted_;
  int direction_;
  bool drive_state_;
};

class MiniBot {
public:
  MiniBot();
  moveForward();
  moveBackward();
  turnLeft();
  turnRight();
  void drive();
  void stop();
private:
  Motor left_motor_;
  Motor right_motor_;
  Servo gripper_;
  Servo lifter_;
};

} // namespace nurc

#endif // MINI_BOT_H
