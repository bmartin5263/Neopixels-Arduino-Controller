//
// Created by Brandon on 12/24/24.
//

#include "Effect.h"
#include "NeopixelLine.h"

auto Effect::update() -> void {
  if (time++ >= 60) {
    pixel += 1;
    if (pixel >= 16) {
      pixel = 0;
    }
    time = 0;
  }
}

auto Effect::draw(NeopixelLine& line) -> void {
  line.setColor(pixel, Color::BLUE());
}

auto Effect::setColor(const Color& color) -> void {
  this->color = color;
}