//
// Created by Brandon on 12/27/24.
//

#include "ColorGenerators.h"

auto BlueRedGenerator::generate(u32 time, u8 offset, u8 phase, u8 speed) -> Color {
  return {static_cast<u8>(255 - offset * 31), 0, static_cast<u8>(offset * 31)};
}