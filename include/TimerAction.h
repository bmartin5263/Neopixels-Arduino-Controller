//
// Created by Brandon on 12/26/24.
//

#ifndef NEOPIXELS_TIMERACTION_H
#define NEOPIXELS_TIMERACTION_H

#include "TimerId.h"

class TimerAction {
public:
  virtual auto execute(TimerId timerId, u32 globalTime) -> void = 0;
  virtual ~TimerAction() = default;
};

#endif //NEOPIXELS_TIMERACTION_H
