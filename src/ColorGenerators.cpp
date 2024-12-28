//
// Created by Brandon on 12/27/24.
//

#include "ColorGenerators.h"

auto BlueRedGenerator::generate(u32 time, u8 offset, u8 phase, u8 speed) -> Color {
  return {static_cast<u8>(255 - offset * 31), 0, static_cast<u8>(offset * 31)};
}

auto RainbowGenerator::generate(u32 time, u8 offset, u8 phase, u8 speed) -> Color {
  auto t = time / 2;
  auto h = (t % 256) / 255.0;
  return Color::HslToRgb(h, 1.0, .5);
}