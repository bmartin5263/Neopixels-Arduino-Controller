#include <Arduino.h>
#include "Log.h"
#include "Timer.h"
#include "Demo.h"

Demo demo;

void setup() {
  Log::init();
  demo.setup();
}

void update() {
  Timer::Update();
  demo.update();
}

void draw() {
  demo.draw();
}

void loop() {
  update();
  draw();
}