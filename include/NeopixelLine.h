//
// Created by Brandon on 12/25/24.
//

#ifndef NEOPIXELS_NEOPIXELLINE_H
#define NEOPIXELS_NEOPIXELLINE_H

#include <../lib/AdafruitNeopixel/Adafruit_NeoPixel.h>
#include "Types.h"

struct Color;
class Adafruit_NeoPixel;
class NeopixelLine {
public:
  NeopixelLine(u16 ledCount, i16 pinNumber, neoPixelType type);

  auto init() -> void;

  auto clear() -> void;

  auto show() -> void;

  auto setBrightness(u8 value) -> void;

  auto setColor(u16 pixel, const Color& color) -> void;

  auto setColor(u16 pixel, u8 r, u8 g, u8 b, u8 w) -> void;

  auto getColor(u16 pixel) -> Color;

  virtual ~NeopixelLine() = default;

private:
  Adafruit_NeoPixel impl;
};

#endif //NEOPIXELS_NEOPIXELLINE_H
