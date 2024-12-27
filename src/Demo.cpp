//
// Created by Brandon on 12/25/24.
//

#include "Demo.h"

static float h = 0.33; // Hue [0, 1]
static float s = 1.0; // Saturation [0, 1]
static float l = .5;  // Lightness [0, 1]
static int timer = 0;

float normalize(float value) {
  // Ensure input is within valid range
  if (value <= 5.0f) {
    return 85.0f;
  }
  if (value >= 130.0f) {
    return 11.0f;
  }

  // Perform linear mapping
  float input_min = 5.0f;
  float input_max = 130.0f;
  float output_min = 70.0f;
  float output_max = 9.0f;

  return output_min + (output_max - output_min) * (value - input_min) / (input_max - input_min);
}

float normalize2(float value) {
  // Ensure input is within valid range
  if (value <= 0.0f) {
    return 0.0f;
  }
  if (value >= .4f) {
    return 150.0f;
  }

  // Perform linear mapping
  float input_min = 0.0f;
  float input_max = .4f;
  float output_min = 0.0f;
  float output_max = 150.0f;

  return output_min + (output_max - output_min) * (value - input_min) / (input_max - input_min);
}

auto Demo::init() -> void {
  ring.init();
  ring.setBrightness(10);

  accelerate.init();
  decelerate.init();
}

auto Demo::update() -> void {
  accelerate.update();
  if (accelerate.getState() == ButtonState::PRESS) {
    accelerating = true;
  }

  decelerate.update();
  if (decelerate.getState() == ButtonState::PRESS) {
    accelerating = false;
  }

  if (accelerating) {
    car.accelerate();
  }

  car.update();

  effectTrailing.setMoveRate(normalize(car.getSpeed()));
  unsigned char x = normalize2(car.getAcceleration());

  int blue = 155 - (x * 1.2);
  if (blue < 0) {
    blue = 0;
  }
  auto blueChar = (unsigned char)blue;

  int red = 100 + (x * .3);
  if (red > 255) {
    red = 255;
  }
  auto redChar = (unsigned char)red;

  effectTrailing.setColor({redChar, 0, blueChar});
  effectTrailing.update();
}

auto Demo::draw() -> void {
  ring.clear();
  effectTrailing.draw(ring);
  ring.show();
}