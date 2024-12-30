//
// Created by Brandon on 12/25/24.
//

#ifndef NEOPIXELS_NEOPIXELLINE_H
#define NEOPIXELS_NEOPIXELLINE_H

#include "Adafruit_NeoPixel.h"
#include "ColorProxy.h"
#include "Types.h"

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
  auto operator[](u16) -> ColorProxy;

  auto fill(const Color& color) -> void;
  auto fill(u8 r, u8 g, u8 b, u8 w) -> void;

  auto fill(const Color& color, u16 length, u16 offset = 0) -> void;
  auto fill(u8 r, u8 g, u8 b, u8 w, u16 length, u16 offset = 0) -> void;

  auto count() -> u16;

  auto reverse() -> void;
  auto getPixel(u16 value) -> u16;

private:
  Adafruit_NeoPixel impl;
  int offset;
};

#endif //NEOPIXELS_NEOPIXELLINE_H
