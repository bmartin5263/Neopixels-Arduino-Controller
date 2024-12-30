//
// Created by Brandon on 12/29/24.
//

#ifndef NEOPIXELS_FILLEFFECT_H
#define NEOPIXELS_FILLEFFECT_H

#include "TrailingColorGenerator.h"

class TrailingColorGenerator;
class NeopixelLine;
class FillEffect {
public:
  auto setColorGenerator(TrailingColorGenerator& colorGenerator) -> FillEffect&;
  auto setLength(u16 value) -> FillEffect&;
  auto setOffset(u16 value) -> FillEffect&;

  auto draw(NeopixelLine& line) -> void;

private:
  TrailingColorGenerator* colorGenerator{&TrailingColorGenerator::Default()};
  u16 length{};
  u16 offset{};
};


#endif //NEOPIXELS_FILLEFFECT_H
