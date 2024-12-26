//
// Created by Brandon on 12/24/24.
//

#include "EffectTrailing.h"
#include "NeopixelRing.h"
#include "Log.h"

typedef struct {
  unsigned char r; // Red component [0, 255]
  unsigned char g; // Green component [0, 255]
  unsigned char b; // Blue component [0, 255]
} RGB;

static double hueToRgb(double p, double q, double t) {
  if (t < 0) t += 1;
  if (t > 1) t -= 1;
  if (t < 1.0 / 6) return p + (q - p) * 6 * t;
  if (t < 1.0 / 2) return q;
  if (t < 2.0 / 3) return p + (q - p) * (2.0 / 3 - t) * 6;
  return p;
}

static RGB hslToRgb(double h, double s, double l) {
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
  RGB rgb;
  rgb.r = (unsigned char)(r * 255);
  rgb.g = (unsigned char)(g * 255);
  rgb.b = (unsigned char)(b * 255);

  return rgb;
}


auto EffectTrailing::update() -> void {
  if (moveTime++ >= 20) {
    move();
    moveTime = 0;
  }

  if (hueTime++ >= 15) {

    h += 0.01;
    if (h > 1.0) {
      h = 0.0;
    }

    hueTime = 0;
  }
}

auto EffectTrailing::move() -> void {
  pixel += 1;
  if (pixel >= 16) {
    pixel = 0;
  }
}

auto EffectTrailing::draw(NeopixelRing& ring) -> void {
  auto p1 = pixel;
  auto p2 = (pixel + 1) % 16;
  auto p3 = (pixel + 2) % 16;
  auto p4 = (pixel + 3) % 16;
  auto p5 = (pixel + 4) % 16;
  auto p6 = (pixel + 5) % 16;

  RGB rgb = hslToRgb(h, 1.0, .5);
  Color color{rgb.r, rgb.g, rgb.b};

  ring.setColor(p1, color);
  ring.setColor(p2, color);
  ring.setColor(p3, color);
  ring.setColor(p4, color);
  ring.setColor(p5, color);
  ring.setColor(p6, color);
}