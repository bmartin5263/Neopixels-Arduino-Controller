//
// Created by Brandon on 12/25/24.
//
#include "NeopixelLine.h"
#include "Adafruit_NeoPixel.h"
#include "Color.h"
#include "Utils.h"

NeopixelLine::NeopixelLine(u16 ledCount, i16 pinNumber, neoPixelType type)
  : impl(ledCount, pinNumber, type) {
}

auto NeopixelLine::init() -> void {
  impl.begin();
  impl.setBrightness(10);
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
  impl.setPixelColor(pixel, color.g, color.r, color.b, color.w);
}

auto NeopixelLine::setColor(u16 pixel, u8 r, u8 g, u8 b, u8 w) -> void {
  // Argument order is intentionally GRB
  impl.setPixelColor(pixel, g, r, b, w);
}

auto NeopixelLine::fill(const Color& color) -> void {
  // Argument order is intentionally GRB
  for (u16 i = 0; i < impl.numPixels(); ++i) {
    impl.setPixelColor(i, color.g, color.r, color.b, color.w);
  }
}

auto NeopixelLine::fill(u8 r, u8 g, u8 b, u8 w) -> void {
  // Argument order is intentionally GRB
  for (u16 i = 0; i < impl.numPixels(); ++i) {
    impl.setPixelColor(i, g, r, b, w);
  }
}

auto NeopixelLine::getColor(u16 pixel) -> Color {
  u8 r, g, b, w;
  u32 rgbw = impl.getPixelColor(pixel);
  extractBytes(rgbw, r, g, b, w);
  return {r, g, b, w};
}

auto NeopixelLine::count() -> u16 {
  return impl.numPixels();
}