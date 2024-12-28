//
// Created by Brandon on 12/8/24.
//

#ifndef NEOPIXELS_DIGITALPIN_H
#define NEOPIXELS_DIGITALPIN_H

#include "Types.h"

class DigitalPin {
public:
  DigitalPin(int number);
  void open(int mode) const;
  bool read() const;
  int number() const;

private:
  u8 _number;
};

#endif //NEOPIXELS_DIGITALPIN_H
