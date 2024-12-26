//
// Created by Brandon on 12/8/24.
//

#ifndef NEOPIXELS_RINGCONTROLLER_H
#define NEOPIXELS_RINGCONTROLLER_H

#include "Color.h"

class NeopixelRing;
template<int N>
class RingController {
public:
  explicit RingController(): pixel(0), pixelChangeTime(0) {
    for (int i = 0; i < N; ++i) {
      colors[i] = Color::OFF();
    }
  }

  auto update() -> void {
  }

  auto draw(NeopixelRing& ring) -> void {
    for (int i = 0; i < N; ++i) {
      ring.setColor(i, colors[i]);
    }
    if (pixelChangeTime > 0) {
      ++pixelChangeTime;
      if (pixelChangeTime >= 50) {
        pixelChangeTime = 0;
      }
      ring.setColor(pixel, Color::WHITE());
    }
  }

  auto nextPixel() -> void {
    pixel += 1;
    if (pixel >= N) {
      pixel = 0;
    }
    pixelChangeTime = 1;
  }

  auto cycleColor() -> void {
    colors[pixel] = Color::cycleColor(colors[pixel]);
  }

  auto setColor(int pixel, const Color& color) -> void {
    colors[pixel] = color;
  }

private:
  int pixel;
  int pixelChangeTime;
  Color colors[N];
};

#endif //NEOPIXELS_RINGCONTROLLER_H
