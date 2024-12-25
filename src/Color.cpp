//
// Created by Brandon on 12/8/24.
//

#include "Color.h"
#include "Log.h"

Color::Color() {

}

Color::Color(u8 r, u8 g, u8 b, u8 w): r(r), g(g), b(b), w(w) {
}

bool Color::operator==(const Color& rhs) const {
  return r == rhs.r && g == rhs.g && b == rhs.b && w == rhs.w;
}

bool Color::operator!=(const Color& rhs) const {
  return !(rhs == *this);
}

Color Color::cycleColor(const Color& color) {
  if (color == Color::RED()) {
    return Color::YELLOW();
  }
  else if (color == Color::YELLOW()) {
    return Color::GREEN();
  }
  else if (color == Color::GREEN()) {
    return Color::AQUA();
  }
  else if (color == Color::AQUA()) {
    return Color::BLUE();
  }
  else if (color == Color::BLUE()) {
    return Color::PURPLE();
  }
  else if (color == Color::PURPLE() || color == Color::WHITE()) {
    return Color::RED();
  } else {
    return Color::WHITE();
  }
}

// CONFIRMING THIS IS CORRECT!!!
auto Color::RED() -> Color {
  static Color c{0, 255, 0, 0};
  return c;
}

auto Color::BLUE() -> Color {
  static Color c{0, 0, 255, 0};
  return c;
}

auto Color::GREEN() -> Color {
  static Color c{255, 0, 0, 0};
  return c;
}

auto Color::PURPLE() -> Color {
  static Color c{0, 255, 255, 0};
  return c;
}

auto Color::YELLOW() -> Color {
  static Color c{255, 255, 0, 0};
  return c;
}

auto Color::AQUA() -> Color {
  static Color c{0, 255, 255, 0};
  return c;
}

auto Color::WHITE() -> Color {
  static Color c{0, 0, 0, 255};
  return c;
}

auto Color::OFF() -> Color {
  static Color c{0, 0, 0, 0};
  return c;
}
