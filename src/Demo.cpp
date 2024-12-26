//
// Created by Brandon on 12/25/24.
//

#include "Demo.h"

static float h = 0.33; // Hue [0, 1]
static float s = 1.0; // Saturation [0, 1]
static float l = .5;  // Lightness [0, 1]
static int timer = 0;

auto Demo::setup() -> void {
  ring.init();
  ring.setBrightness(10);

  nextPixelButton.init();
//  nextPixelButton.onPress([](){
//    effectTrailing.move();
//  });

  nextColorButton.init();
//  nextColorButton.onPress([](){
//    ringController.cycleColor();
//  });

//  Color colors[] = {
//    Color::SALMON(),
//    Color::RED(),
//    Color::ORANGE(),
//    Color::GOLD(),
//    Color::MAROON(),
//    Color::YELLOW(),
//    Color::LIME(),
//    Color::SPRING_GREEN(),
//    Color::GREEN(),
//    Color::AQUAMARINE(),
//    Color::CYAN(),
//    Color::BLUE(),
//    Color::PURPLE(),
//    Color::VIOLET(),
//    Color::INDIGO(),
//    Color::MAGENTA(),
//  };

  Color colors[] = {
    Color::HslToRgb(0, 1.0, .5),
    Color::HslToRgb(.0625, 1.0, .5),
    Color::HslToRgb(.0625 * 2, 1.0, .5),
    Color::HslToRgb(.0625 * 3, 1.0, .5),
    Color::HslToRgb(.0625 * 4, 1.0, .5),
    Color::HslToRgb(.0625 * 5, 1.0, .5),
    Color::HslToRgb(.0625 * 6, 1.0, .5),
    Color::HslToRgb(.0625 * 7, 1.0, .5),
    Color::HslToRgb(.0625 * 8, 1.0, .5),
    Color::HslToRgb(.0625 * 9, 1.0, .5),
    Color::HslToRgb(.0625 * 10, 1.0, .5),
    Color::HslToRgb(.0645 * 11, 1.0, .5),
    Color::HslToRgb(.0645 * 12, 1.0, .5),
    Color::HslToRgb(.0635 * 13, 1.0, .5),
    Color::HslToRgb(.0645 * 14, 1.0, .5),
    Color::HslToRgb(.0655 * 15, 1.0, .5),
  };

  int counter = 0;
  for (auto& color : colors) {
    ringController.setColor(counter++, color);
  }
}

auto Demo::update() -> void {
  effectTrailing.update();
//  nextPixelButton.update();
//  nextColorButton.update();

  timer += 1;
  if (timer >= 8) {

    h += 0.01;
    if (h > 1.0) {
      h = 0.0;
    }

    Color color = Color::HslToRgb(h, s, l);

    for (int i = 0; i < LED_COUNT; ++i) {
//      ringController.setColor(i, color);
    }

    timer = 0;
  }
}

auto Demo::draw() -> void {
  ring.clear();
  ringController.draw(ring);
//  effectTrailing.draw(ring);
  ring.show();
}