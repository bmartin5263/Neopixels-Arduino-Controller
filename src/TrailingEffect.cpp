//
// Created by Brandon on 12/27/24.
//

#include "TrailingEffect.h"
#include "TrailingColorGenerator.h"
#include "Clocks.h"
#include "NeopixelLine.h"
#include "Log.h"

auto TrailingEffect::init(TrailingColorGenerator& colorGenerator, u8 length, u8 speed) -> void {
  this->colorGenerator = &colorGenerator;
  this->length = length;
  this->speed = speed;
}

auto TrailingEffect::update() -> void {
  auto now = Clocks::GlobalTime();
  if ((now % speed) != 0) {
    return;
  }
  ++phase;
}

auto TrailingEffect::draw(NeopixelLine& line) -> void {
  auto now = Clocks::GlobalTime();
  auto pixelCount = line.count();
  for (u8 i = 0; i < length; ++i) {
    auto color = colorGenerator->generate(now, length, i, phase, speed);
    auto pixel = (i + phase) % pixelCount;
    line.setColor(pixel, color);
  }
}