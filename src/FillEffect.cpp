//
// Created by Brandon on 12/29/24.
//

#include "FillEffect.h"
#include "NeopixelLine.h"
#include "Clocks.h"

auto FillEffect::setColorGenerator(TrailingColorGenerator& colorGenerator) -> FillEffect& {
  this->colorGenerator = &colorGenerator;
  return *this;
}

auto FillEffect::setLength(u16 value) -> FillEffect& {
  this->length = value;
  return *this;
}

auto FillEffect::setOffset(u16 value) -> FillEffect& {
  this->offset = value;
  return *this;
}

auto FillEffect::draw(NeopixelLine& line) -> void {
  auto time = Clocks::GlobalTime();
  auto numPixels = line.count();
  for (int i = 0; i < length; ++i) {
    auto pixel = (i + offset) % numPixels;
    line[pixel] = colorGenerator->generate(time, length, i, 0, 0);
  }
}