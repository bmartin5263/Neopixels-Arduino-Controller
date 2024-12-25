//
// Created by Brandon on 12/24/24.
//

#ifndef NEOPIXELS_TIMER_H
#define NEOPIXELS_TIMER_H

#include "TimerId.h"
#include "Func.h"

class Timer {
public:
  static auto SetTimeout(int time, Callable action) -> TimerId;
  static auto SetInterval(int time, Callable action) -> TimerId;
  static auto Cancel(TimerId id) -> void;
  static auto Update() -> void;

private:
  static Timer& Instance();

  auto setTimeout(int time, Callable action) -> TimerId;
  auto setInterval(int time, Callable action) -> TimerId;
  auto cancel(TimerId id) -> void;
  auto update() -> void;
};

#endif //NEOPIXELS_TIMER_H
