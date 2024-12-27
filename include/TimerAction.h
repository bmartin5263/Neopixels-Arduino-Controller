//
// Created by Brandon on 12/26/24.
//

#ifndef NEOPIXELS_TIMERACTION_H
#define NEOPIXELS_TIMERACTION_H

#include "TimerId.h"

class TimerAction {
  auto operator()(TimerId timerId, long globalTime) -> void;
  virtual ~TimerAction();
};

#endif //NEOPIXELS_TIMERACTION_H
