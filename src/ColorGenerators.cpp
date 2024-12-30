//
// Created by Brandon on 12/27/24.
//

#include "ColorGenerators.h"
#include "Log.h"

auto BlueRedGenerator::generate(u32 time, u8 length, u8 offset, u16 phase, u8 speed) -> Color {
  return {static_cast<u8>(255 - offset * 31), 0, static_cast<u8>(offset * 31)};
}

auto RainbowGenerator::generate(u32 time, u8 length, u8 offset, u16 phase, u8 speed) -> Color {
  auto h = (time % 256) / 255.0f;
  return Color::HslToRgb(h, 1.0f, .5f);
}

StaticColorGenerator::StaticColorGenerator(const Color& color): color(color) {
}

auto StaticColorGenerator::setColor(const Color& color) -> void {
  this->color = color;
}

auto StaticColorGenerator::generate(u32 time, u8 length, u8 offset, u16 phase, u8 speed) -> Color {
  return color;
}