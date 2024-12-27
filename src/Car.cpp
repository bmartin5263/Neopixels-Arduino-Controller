//
// Created by Brandon on 12/26/24.
//

#include "Car.h"

auto Car::accelerate() -> void {
//  if (acceleration < 0.0f) {
//    acceleration += .7f;
//  }
  if (acceleration < .8f) {
    acceleration += .004f;
  }
  if (acceleration > maxAcceleration) {
    maxAcceleration = acceleration;
  }
}

auto Car::brake() -> void {
  acceleration -= .1f;
}

auto Car::update() -> void {
  speed += (acceleration * .3f);
  if (speed < 0.0f) {
    speed = 0.0f;
  }
  if (speed >= 130.0f) {
    speed = 130.0f;
  }

  auto min = -.5f;
  if (acceleration > min) {
    acceleration -= .002f;
    if (acceleration < min) {
      acceleration = min;
    }
  }
}

auto Car::draw() -> void {

}

auto Car::getSpeed() -> float const {
  return speed;
}

auto Car::getAcceleration() -> float const {
  return acceleration;
}