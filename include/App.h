//
// Created by Brandon on 12/26/24.
//

#ifndef NEOPIXELS_APP_H
#define NEOPIXELS_APP_H

#include "Demo.h"

class App {
public:
  auto init() -> void;
  auto loop() -> void;

private:
  Demo demo;

  auto update() -> void;
  auto draw() -> void;
  auto updateSubsystems() -> void;

};

#endif //NEOPIXELS_APP_H
