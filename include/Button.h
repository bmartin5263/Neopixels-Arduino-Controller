//
// Created by Brandon on 12/8/24.
//

#ifndef NEOPIXELS_BUTTON_H
#define NEOPIXELS_BUTTON_H

#include <Arduino.h>
#include "Types.h"
#include "Func.h"
#include "ButtonState.h"
#include "DigitalPin.h"

class Button {
public:
  Button(DigitalPin pin);
  auto init() -> Button&;
  auto update() -> void;
  auto getState() -> ButtonState;

private:
  ButtonState state;
  u16 timeInState;
  u16 _repeatDelay;
  Callable _onPress;
  DigitalPin pin;
};

#endif //NEOPIXELS_BUTTON_H
