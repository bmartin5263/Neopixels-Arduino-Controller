//
// Created by Brandon on 12/24/24.
//

#include "EffectTrailing.h"
#include "NeopixelLine.h"
#include "Log.h"

auto EffectTrailing::update() -> void {
  if (moveTime++ >= moveRate) {
    move();
    moveTime = 0;
  }

  if (hueTime++ >= 40) {
    h += 0.01f;
    if (h > 1.0f) {
      h = 0.0f;
    }
    hueTime = 0;
  }
}

auto EffectTrailing::move() -> void {
  pixel += 1;
  if (pixel >= 16) {
    pixel = 0;
  }
}

auto EffectTrailing::draw(NeopixelLine& ring) -> void {
  for (int i = 0; i < 6; ++i) {
    auto p = (pixel + i) % 16;
    ring.setColor(p, color);
  }
}

auto EffectTrailing::setMoveRate(int value) -> void {
//  if (value > moveRate) {
//    moveTime = moveRate;
//  }
  moveRate = value;
}

auto EffectTrailing::setColor(const Color& value) -> void {
  color = value;
}