//
// Created by Brandon on 12/8/24.
//

#ifndef NEOPIXELS_BUTTON_H
#define NEOPIXELS_BUTTON_H

#include <Arduino.h>
#include "Types.h"
#include "Func.h"
#include "ButtonState.h"

class DigitalPin;
class Button {
public:
  Button(DigitalPin* pin);
  auto init() -> Button&;
  auto update() -> void;
  auto getState() -> ButtonState;

private:
  DigitalPin* pin;
  ButtonState state;
  int timeInState;
  int _repeatDelay;
  Callable _onPress;
};

#endif //NEOPIXELS_BUTTON_H
