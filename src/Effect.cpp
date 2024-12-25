//
// Created by Brandon on 12/24/24.
//

#include "Effect.h"
#include "NeopixelRing.h"

auto Effect::update() -> void {
  if (time++ >= 60) {
    pixel += 1;
    if (pixel >= 16) {
      pixel = 0;
    }
    time = 0;
  }
}

auto Effect::draw(NeopixelRing& ring) -> void {
  ring.setColor(pixel, Color::BLUE());
}

auto Effect::setColor(const Color& color) -> void {
  this->color = color;
}