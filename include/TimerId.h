//
// Created by Brandon on 12/24/24.
//

#ifndef NEOPIXELS_TIMERID_H
#define NEOPIXELS_TIMERID_H

#include "USBAPI.h"

struct TimerNode;
struct TimerId {
  TimerId();
  TimerId(void* node, u16 version);

  void* pimpl{};
  u16 version{};
};

#endif //NEOPIXELS_TIMERID_H
