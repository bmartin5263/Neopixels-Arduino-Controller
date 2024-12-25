//
// Created by Brandon on 12/8/24.
//

#ifndef NEOPIXELS_NEOPIXELRING_H
#define NEOPIXELS_NEOPIXELRING_H

#include <../lib/AdafruitNeopixel/Adafruit_NeoPixel.h>
#include "Types.h"

class Color;
class NeopixelRing {
public:
  NeopixelRing(u16 ledCount, i16 pinNumber, neoPixelType type);
  auto init() -> void;
  auto clear() -> void;
  auto draw() -> void;
  auto setBrightness(u8 value) -> void;
  auto setColor(u16 pixel, const Color& color) -> void;
  auto setColor(u16 pixel, u8 r, u8 g, u8 b, u8 w) -> void;

private:
  Adafruit_NeoPixel impl;

};

#endif //NEOPIXELS_NEOPIXELRING_H