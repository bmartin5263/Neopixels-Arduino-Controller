//
// Created by Brandon on 12/26/24.
//

#ifndef NEOPIXELS_TRAILINGCOLORGENERATOR_H
#define NEOPIXELS_TRAILINGCOLORGENERATOR_H

#include "ColorGenerator.h"
#include "Types.h"

class NeopixelLine;
class TrailingColorGenerator : public ColorGenerator {
public:
  auto generate(long time) -> Color override;
  virtual auto generate(u32 time, NeopixelLine* line, u8 pixel) -> Color = 0;
  virtual ~TrailingColorGenerator() = default;
};

#endif //NEOPIXELS_TRAILINGCOLORGENERATOR_H
