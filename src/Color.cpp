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
    return Color::CYAN();
  }
  else if (color == Color::CYAN()) {
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

auto Color::RED() -> Color {
  static Color c{255, 0, 0, 0};
  return c;
}

auto Color::ORANGE() -> Color {
  static Color c{255, 64, 0, 0};
  return c;
}

auto Color::SALMON() -> Color {
  static Color c{250, 128, 114, 0};
  return c;
}

auto Color::GOLD() -> Color {
  static Color c{255, 128, 0, 0};
  return c;
}

auto Color::MAROON() -> Color {
  static Color c{255, 215, 0, 0};
  return c;
}

auto Color::YELLOW() -> Color {
  static Color c{255, 255, 0, 0};
  return c;
}

auto Color::LIME() -> Color {
  static Color c{191, 255, 0, 0};
  return c;
}

auto Color::SPRING_GREEN() -> Color {
  static Color c{0, 255, 127, 0};
  return c;
}

auto Color::GREEN() -> Color {
  static Color c{0, 255, 0, 0};
  return c;
}

auto Color::AQUAMARINE() -> Color {
  static Color c{127, 255, 212, 0};
  return c;
}

auto Color::CYAN() -> Color {
  static Color c{0, 255, 255, 0};
  return c;
}

auto Color::BLUE() -> Color {
  static Color c{0, 0, 255, 0};
  return c;
}

auto Color::PURPLE() -> Color {
  static Color c{106, 13, 173, 0};
  return c;
}

auto Color::VIOLET() -> Color {
  static Color c{128, 0, 255, 0};
  return c;
}

auto Color::INDIGO() -> Color {
  static Color c{75, 0, 130, 0};
  return c;
}

auto Color::MAGENTA() -> Color {
  static Color c{255, 0, 255, 0};
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


