//
// Created by Brandon on 12/26/24.
//

#ifndef NEOPIXELS_SIMPLETRAILINGCOLORGENERATOR_H
#define NEOPIXELS_SIMPLETRAILINGCOLORGENERATOR_H

#include "ColorGenerator.h"
#include "Types.h"

class NeopixelLine;
class SimpleTrailingColorGenerator : public ColorGenerator {
public:
  explicit SimpleTrailingColorGenerator(ColorGenerator* delegate);
  auto generate(long time) -> Color override;
  auto generate(u32 time, NeopixelLine* line, u8 pixel) -> Color;

private:
  ColorGenerator* delegate;

};

#endif //NEOPIXELS_SIMPLETRAILINGCOLORGENERATOR_H
