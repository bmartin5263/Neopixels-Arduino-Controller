//
// Created by Brandon on 12/8/24.
//

#ifndef NEOPIXELS_COLOR_H
#define NEOPIXELS_COLOR_H

#include "Types.h"

struct Color {
  Color();
  Color(u8 r, u8 g, u8 b, u8 w = 0);

  bool operator==(const Color& rhs) const;
  bool operator!=(const Color& rhs) const;

  static Color CycleColor(const Color& color);

  u8 r{};
  u8 g{};
  u8 b{};
  u8 w{};

  // https://simple.wikipedia.org/wiki/List_of_colors

  static auto RED() -> Color;
  static auto MAROON() -> Color;
  static auto SALMON() -> Color;

  static auto ORANGE() -> Color;
  static auto GOLD() -> Color;
  static auto YELLOW() -> Color;

  static auto LIME() -> Color;
  static auto SPRING_GREEN() -> Color;
  static auto GREEN() -> Color;

  static auto AQUAMARINE() -> Color;
  static auto CYAN() -> Color;
  static auto BLUE() -> Color;

  static auto PURPLE() -> Color;
  static auto VIOLET() -> Color;
  static auto INDIGO() -> Color;
  static auto MAGENTA() -> Color;

  static auto WHITE() -> Color;
  static auto OFF() -> Color;

  static Color HslToRgb(double h, double s, double l);

private:
  static double hueToRgb(double p, double q, double t);
};

#endif //NEOPIXELS_COLOR_H
