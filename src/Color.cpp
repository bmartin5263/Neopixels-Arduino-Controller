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

auto Color::redShift(u8 amount) const -> Color {
  return {static_cast<u8>(r + amount), g, b, w};
}

auto Color::greenShift(u8 amount) const -> Color {
  return {r, static_cast<u8>(g + amount), b, w};
}

auto Color::blueShift(u8 amount) const -> Color {
  return {r, g, static_cast<u8>(b + amount), w};
}

auto Color::whiteShift(u8 amount) const -> Color {
  return {r, g, b, static_cast<u8>(w + amount)};
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

auto Color::RED() -> const Color& {
  static Color c{255, 0, 0, 0};
  return c;
}

auto Color::RED(u8 intensity) -> Color {
  return {intensity, 0, 0, 0};
}

auto Color::ORANGE() -> const Color& {
  static Color c{255, 64, 0, 0};
  return c;
}

auto Color::SALMON() -> const Color& {
  static Color c{250, 128, 114, 0};
  return c;
}

auto Color::GOLD() -> const Color& {
  static Color c{255, 128, 0, 0};
  return c;
}

auto Color::MAROON() -> const Color& {
  static Color c{255, 215, 0, 0};
  return c;
}

auto Color::YELLOW(u8 intensity) -> Color {
  return {intensity, intensity, 0, 0};
}

auto Color::YELLOW() -> const Color& {
  static Color c{255, 255, 0, 0};
  return c;
}

auto Color::LIME() -> const Color& {
  static Color c{191, 255, 0, 0};
  return c;
}

auto Color::SPRING_GREEN() -> const Color& {
  static Color c{0, 255, 127, 0};
  return c;
}

auto Color::GREEN() -> const Color& {
  static Color c{0, 255, 0, 0};
  return c;
}

auto Color::GREEN(u8 intensity) -> Color {
  return {0, intensity, 0, 0};
}

auto Color::AQUAMARINE() -> const Color& {
  static Color c{127, 255, 212, 0};
  return c;
}

auto Color::CYAN() -> const Color& {
  static Color c{0, 255, 255, 0};
  return c;
}

auto Color::CYAN(u8 intensity) -> Color {
  return {0, intensity, intensity, 0};
}

auto Color::BLUE() -> const Color& {
  static Color c{0, 0, 255, 0};
  return c;
}

auto Color::BLUE(u8 intensity) -> Color {
  return {0, 0, intensity, 0};
}

auto Color::PURPLE() -> const Color& {
  static Color c{106, 13, 173, 0};
  return c;
}

auto Color::VIOLET() -> const Color& {
  static Color c{128, 0, 255, 0};
  return c;
}

auto Color::INDIGO() -> const Color& {
  static Color c{75, 0, 130, 0};
  return c;
}

auto Color::MAGENTA() -> const Color& {
  static Color c{255, 0, 255, 0};
  return c;
}

auto Color::MAGENTA(u8 intensity) -> Color {
  return {intensity, 0, intensity, 0};
}

auto Color::WHITE(u8 intensity) -> Color {
  return {0, 0, 0, intensity};
}

auto Color::OFF() -> const Color& {
  static Color c{0, 0, 0, 0};
  return c;
}

float Color::HueToRgb(float p, float q, float t) {
  if (t < 0) t += 1;
  if (t > 1) t -= 1;
  if (t < 1.0f / 6) return p + (q - p) * 6 * t;
  if (t < 1.0f / 2) return q;
  if (t < 2.0f / 3) return p + (q - p) * (2.0f / 3 - t) * 6;
  return p;
}

Color Color::HslToRgb(float h, float s, float l) {
  float r, g, b;

  if (s == 0.f) {
    // Achromatic (gray)
    r = g = b = l;
  } else {
    float q = l < 0.5f ? l * (1 + s) : l + s - l * s;
    float p = 2 * l - q;
    r = HueToRgb(p, q, h + 1.0f / 3);
    g = HueToRgb(p, q, h);
    b = HueToRgb(p, q, h - 1.0f / 3);
  }

  // Convert to 0-255 range
  return {FloatToByte(r), FloatToByte(g), FloatToByte(b)};
}

auto Color::ByteToFloat(u8 b) -> float {
  return (float)b / 255;
}

auto Color::FloatToByte(float f, u8 range) -> u8 {
  return ((u8)(f * range)) % (range + 1);
}
