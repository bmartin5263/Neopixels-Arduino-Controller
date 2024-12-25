//
// Created by Brandon on 12/8/24.
//

#include <Arduino.h>
#include "DigitalPin.h"

DigitalPin::DigitalPin(int number): _number(number) {

}

auto DigitalPin::open(int mode) const -> void {
  pinMode(_number, mode);
}

bool DigitalPin::read() const {
  return digitalRead(_number);
}

int DigitalPin::number() const {
  return _number;
}