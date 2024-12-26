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

Color Color::CycleColor(const Color& color) {
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

double Color::hueToRgb(double p, double q, double t) {
  if (t < 0) t += 1;
  if (t > 1) t -= 1;
  if (t < 1.0 / 6) return p + (q - p) * 6 * t;
  if (t < 1.0 / 2) return q;
  if (t < 2.0 / 3) return p + (q - p) * (2.0 / 3 - t) * 6;
  return p;
}

Color Color::HslToRgb(double h, double s, double l) {
  double r, g, b;

  if (s == 0) {
    // Achromatic (gray)
    r = g = b = l;
  } else {
    double q = l < 0.5 ? l * (1 + s) : l + s - l * s;
    double p = 2 * l - q;
    r = hueToRgb(p, q, h + 1.0 / 3);
    g = hueToRgb(p, q, h);
    b = hueToRgb(p, q, h - 1.0 / 3);
  }

  // Convert to 0-255 range
  return {(unsigned char)(r * 255), (unsigned char)(g * 255), (unsigned char)(b * 255)};
}


