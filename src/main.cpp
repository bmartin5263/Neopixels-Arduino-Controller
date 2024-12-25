#include <Arduino.h>
#include "Button.h"
#include "NeopixelRing.h"
#include "DigitalPin.h"
#include "Log.h"
#include "RingController.h"
#include "Effect.h"
#include "EffectTrailing.h"
#include "Timer.h"

constexpr int LED_PIN = 4;
constexpr int LED_COUNT = 16;

DigitalPin pin2{2};
DigitalPin pin3{3};
NeopixelRing ring{LED_COUNT, LED_PIN, NEO_RGBW + NEO_KHZ800};
Button nextPixelButton{&pin3};
Button nextColorButton{&pin2};
RingController<16> ringController{};
Effect effect{};
EffectTrailing effectTrailing{};

void setup() {
  Log::init();

  ring.init();
  ring.setBrightness(10);
  nextPixelButton.init();
  nextPixelButton.onPress([](){
    effectTrailing.move();
  });

  nextColorButton.init();
  nextColorButton.onPress([](){
    ringController.cycleColor();
  });
}

void update() {
  Timer::Update();
  effectTrailing.update();
  nextPixelButton.update();
  nextColorButton.update();
}

void draw() {
  ring.clear();
  ringController.draw(ring);
  effectTrailing.draw(ring);
  ring.draw();
}

void loop() {
  update();
  draw();
}