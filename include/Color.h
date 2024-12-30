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

  auto redShift(u8 amount) const -> Color;
  auto greenShift(u8 amount) const -> Color;
  auto blueShift(u8 amount) const -> Color;
  auto whiteShift(u8 amount) const -> Color;

  static Color CycleColor(const Color& color);

  u8 r{};
  u8 g{};
  u8 b{};
  u8 w{};

  // https://simple.wikipedia.org/wiki/List_of_colors

  static auto RED() -> const Color&;
  static auto RED(u8 intensity) -> Color;
  static auto MAROON() -> const Color&;
  static auto SALMON() -> const Color&;

  static auto ORANGE() -> const Color&;
  static auto GOLD() -> const Color&;
  static auto YELLOW() -> const Color&;
  static auto YELLOW(u8 intensity) -> Color;

  static auto LIME() -> const Color&;
  static auto SPRING_GREEN() -> const Color&;
  static auto GREEN() -> const Color&;
  static auto GREEN(u8 intensity) -> Color;

  static auto AQUAMARINE() -> const Color&;
  static auto CYAN() -> const Color&;
  static auto CYAN(u8 intensity) -> Color;
  static auto BLUE() -> const Color&;
  static auto BLUE(u8 intensity) -> Color;

  static auto PURPLE() -> const Color&;
  static auto VIOLET() -> const Color&;
  static auto INDIGO() -> const Color&;
  static auto MAGENTA() -> const Color&;
  static auto MAGENTA(u8 intensity) -> Color;

  static auto WHITE() -> const Color&;
  static auto WHITE(u8 intensity) -> Color;
  static auto OFF() -> const Color&;

  static auto HslToRgb(float h, float s = 1.0f, float l = .5f) -> Color;

  static auto ByteToFloat(u8 b) -> float;
  static auto FloatToByte(float f, u8 range = 255) -> u8;

private:
  static float HueToRgb(float p, float q, float t);
};

#endif //NEOPIXELS_COLOR_H
