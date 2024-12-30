//
// Created by Brandon on 12/27/24.
//

#ifndef NEOPIXELS_COLORGENERATORS_H
#define NEOPIXELS_COLORGENERATORS_H

#include "TrailingColorGenerator.h"

class BlueRedGenerator : public TrailingColorGenerator {
public:
  auto generate(u32 time, u8 length, u8 offset, u16 phase, u8 speed) -> Color override;
};

class RainbowGenerator : public TrailingColorGenerator {
public:
  auto generate(u32 time, u8 length, u8 offset, u16 phase, u8 speed) -> Color override;
};

class StaticColorGenerator : public TrailingColorGenerator {
public:
  StaticColorGenerator(const Color& color);
  auto setColor(const Color& color) -> void;
  auto generate(u32 time, u8 length, u8 offset, u16 phase, u8 speed) -> Color override;
private:
  Color color;
};

#endif //NEOPIXELS_COLORGENERATORS_H
