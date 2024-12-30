//
// Created by Brandon on 12/29/24.
//

#ifndef NEOPIXELS_COLORPROXY_H
#define NEOPIXELS_COLORPROXY_H

#include "Color.h"

class NeopixelLine;
class ColorProxy {
public:
  ColorProxy(NeopixelLine* line, u16 pixel);
  auto operator=(const Color& color) -> ColorProxy&;

private:
  NeopixelLine* line;
  u16 pixel;
};

#endif //NEOPIXELS_COLORPROXY_H
