//
// Created by Brandon on 12/29/24.
//

#include "ColorProxy.h"
#include "NeopixelLine.h"

auto ColorProxy::operator=(const Color& color) -> ColorProxy& {
  line->setColor(pixel, color);
  return *this;
}

ColorProxy::ColorProxy(NeopixelLine* line, u16 pixel) : line(line), pixel(pixel) {}
