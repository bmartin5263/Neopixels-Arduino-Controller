//
// Created by Brandon on 12/8/24.
//
#include <Arduino.h>
#include "DigitalPin.h"
#include "Button.h"

Button::Button(DigitalPin pin)
  : state(ButtonState::UNPRESSED), timeInState(0), _repeatDelay(0), _onPress([](){}), pin(pin)
{
}

auto Button::init() -> Button& {
  pin.open(INPUT);
  return *this;
}

auto Button::update() -> void {
  timeInState += 1;

  auto pressed = pin.read();
  if (state == ButtonState::UNPRESSED || state == ButtonState::UNPRESS) {
    state = pressed ? ButtonState::PRESS : ButtonState::UNPRESSED;
  }
  else if (state == ButtonState::PRESS || state == ButtonState::PRESSED) {
    state = pressed ? ButtonState::PRESSED : ButtonState::UNPRESS;
  }
}

auto Button::getState() -> ButtonState {
  return state;
}
