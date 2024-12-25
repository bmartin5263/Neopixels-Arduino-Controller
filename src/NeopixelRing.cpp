//
// Created by Brandon on 12/8/24.
//

#include "NeopixelRing.h"
#include "Color.h"

NeopixelRing::NeopixelRing(u16 ledCount, i16 pinNumber, neoPixelType type)
  : impl(ledCount, pinNumber, type) {

}

auto NeopixelRing::init() -> void {
  impl.begin();
}

auto NeopixelRing::setBrightness(u8 value) -> void {
  impl.setBrightness(value);
}

auto NeopixelRing::setColor(u16 pixel, const Color& color) -> void {
  impl.setPixelColor(pixel, color.r, color.g, color.b, color.w);
}

auto NeopixelRing::setColor(u16 pixel, u8 r, u8 g, u8 b, u8 w) -> void {
  impl.setPixelColor(pixel, r, g, b, w);
}

auto NeopixelRing::clear() -> void {
  impl.clear();
}

auto NeopixelRing::draw() -> void {
  impl.show();
}