//
// Created by Brandon on 12/25/24.
//
#include "NeopixelLine.h"
#include "Color.h"
#include "Utils.h"
#include "Log.h"

NeopixelLine::NeopixelLine(u16 ledCount, i16 pinNumber, neoPixelType type)
  : impl(ledCount, pinNumber, type), offset(0) {
}

auto NeopixelLine::init() -> void {
  impl.begin();
  impl.setBrightness(6);
}

auto NeopixelLine::clear() -> void {
  impl.clear();
}

auto NeopixelLine::show() -> void {
  impl.show();
}

auto NeopixelLine::setBrightness(u8 value) -> void {
  impl.setBrightness(value);
}

auto NeopixelLine::setColor(u16 pixel, const Color& color) -> void {
  // Argument order is intentionally GRB
  impl.setPixelColor(getPixel(pixel), color.g, color.r, color.b, color.w);
}

auto NeopixelLine::setColor(u16 pixel, u8 r, u8 g, u8 b, u8 w) -> void {
  // Argument order is intentionally GRB
  impl.setPixelColor(getPixel(pixel), g, r, b, w);
}

auto NeopixelLine::fill(const Color& color) -> void {
  // Argument order is intentionally GRB
  for (u16 pixel = 0; pixel < impl.numPixels(); ++pixel) {
    impl.setPixelColor(getPixel(pixel), color.g, color.r, color.b, color.w);
  }
}

auto NeopixelLine::fill(u8 r, u8 g, u8 b, u8 w) -> void {
  // Argument order is intentionally GRB
  for (u16 pixel = 0; pixel < impl.numPixels(); ++pixel) {
    impl.setPixelColor(getPixel(pixel), g, r, b, w);
  }
}

auto NeopixelLine::fill(const Color& color, u16 length, u16 offset) -> void {
  fill(color.r, color.g, color.b, color.w, length, offset);
}

auto NeopixelLine::fill(u8 r, u8 g, u8 b, u8 w, u16 length, u16 offset) -> void {
  u16 numPixels = impl.numPixels();
  if (length > numPixels) {
    length = numPixels;
  }

  for (u16 i = 0; i < length; ++i) {
    u16 pixel = (i + offset) % numPixels;
    impl.setPixelColor(getPixel(pixel), g, r, b, w);
  }
}

auto NeopixelLine::getColor(u16 pixel) -> Color {
  u8 r, g, b, w;
  u32 rgbw = impl.getPixelColor(pixel);
  ExtractBytes(rgbw, r, g, b, w);
  return {r, g, b, w};
}

auto NeopixelLine::operator[](u16 pixel) -> ColorProxy {
  return {this, pixel};
}

auto NeopixelLine::count() -> u16 {
  return impl.numPixels();
}

auto NeopixelLine::reverse() -> void {
  if (offset == 0) {
    offset = count() - 1;
  }
  else {
    offset = 0;
  }
}

auto NeopixelLine::getPixel(u16 value) -> u16 {
  auto x = abs(offset - value);
//  Log::InfoLn((u32) x);
  return x;
}