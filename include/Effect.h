//
// Created by Brandon on 12/24/24.
//

#ifndef NEOPIXELS_EFFECT_H
#define NEOPIXELS_EFFECT_H

#include "Color.h"

class NeopixelRing;
class Effect {
public:
  auto update() -> void;
  auto draw(NeopixelRing& ring) -> void;
  auto setColor(const Color& color) -> void;

private:
  int time{};
  int pixel{};
  Color color{Color::RED()};
};

#endif //NEOPIXELS_EFFECT_H
