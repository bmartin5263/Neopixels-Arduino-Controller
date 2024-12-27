//
// Created by Brandon on 12/26/24.
//

#ifndef NEOPIXELS_TIMERNODE_H
#define NEOPIXELS_TIMERNODE_H

#include "Types.h"
#include "USBAPI.h"

class TimerAction;
struct TimerNode {
  u32 executeAt{};
  u16 version{};
  TimerNode* prev{};
  TimerNode* next{};
  TimerAction* action{};
  bool cancelled{};

  auto detach() -> void;
  auto execute(u32 time) -> void;
};

#endif //NEOPIXELS_TIMERNODE_H
