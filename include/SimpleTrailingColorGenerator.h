//
// Created by Brandon on 12/26/24.
//

#ifndef NEOPIXELS_SIMPLETRAILINGCOLORGENERATOR_H
#define NEOPIXELS_SIMPLETRAILINGCOLORGENERATOR_H

#include "TrailingColorGenerator.h"
#include "Types.h"

class NeopixelLine;
class SimpleTrailingColorGenerator : public TrailingColorGenerator {
public:
  explicit SimpleTrailingColorGenerator(ColorGenerator* delegate);
  auto generate(u32 time) -> Color override;
  auto generate(u32 time, u8 offset, u8 phase, u8 speed) -> Color override;

private:
  ColorGenerator* delegate;

};

#endif //NEOPIXELS_SIMPLETRAILINGCOLORGENERATOR_H
