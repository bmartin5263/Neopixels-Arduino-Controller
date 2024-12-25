//
// Created by Brandon on 12/8/24.
//

#ifndef NEOPIXELS_COLOR_H
#define NEOPIXELS_COLOR_H

#include "Types.h"

struct Color {
  Color();
  Color(u8 r, u8 g, u8 b, u8 w);

  bool operator==(const Color& rhs) const;
  bool operator!=(const Color& rhs) const;

  static Color cycleColor(const Color& color);

  u8 r{};
  u8 g{};
  u8 b{};
  u8 w{};

  static auto RED() -> Color;
  static auto GREEN() -> Color;
  static auto BLUE() -> Color;
  static auto AQUA() -> Color;
  static auto PURPLE() -> Color;
  static auto YELLOW() -> Color;
  static auto WHITE() -> Color;
  static auto OFF() -> Color;
};

#endif //NEOPIXELS_COLOR_H
