//
// Created by Brandon on 12/24/24.
//

#include "EffectTrailing.h"
#include "NeopixelRing.h"
#include "Log.h"

auto EffectTrailing::update() -> void {
  if (moveTime++ >= 60) {
    move();
    moveTime = 0;
  }

  if (cycleTime++ >= 120) {
    cycle += 1;
    if (cycle >= 5) {
      cycle = 0;
    }
    cycleTime = 0;
  }
}

auto EffectTrailing::move() -> void {
  pixel += 1;
  if (pixel >= 16) {
    pixel = 0;
  }
}

auto EffectTrailing::draw(NeopixelRing& ring) -> void {
//  auto c1 = Color::BLUE();
//  auto c2 = Color{0, 55, 200, 0};
//  auto c3 = Color{0, 105, 150, 0};
//  auto c4 = Color{0, 155, 100, 0};
//  auto c5 = Color{0, 255, 0, 0};

  Color rgb[] = {Color::RED(), Color::YELLOW(), Color::GREEN(), Color::BLUE(), Color::PURPLE()};
  int colors = 5;

  auto c1 = rgb[cycle];
  auto c2 = rgb[(cycle + 1) % 5];
  auto c3 = rgb[(cycle + 2) % 5];
  auto c4 = rgb[(cycle + 3) % 5];
  auto c5 = rgb[(cycle + 4) % 5];

  auto p1 = pixel;
  auto p2 = (pixel + 1) % 16;
  auto p3 = (pixel + 2) % 16;
  auto p4 = (pixel + 3) % 16;
  auto p5 = (pixel + 4) % 16;

  ring.setColor(p1, c5);
  ring.setColor(p2, c4);
  ring.setColor(p3, c3);
  ring.setColor(p4, c2);
  ring.setColor(p5, c1);
}