//
// Created by Brandon on 12/27/24.
//

#include "Assert.h"
#include "TimerDemo.h"
#include "Timer.h"
#include "Color.h"
#include "Log.h"

auto TimerDemo::init() -> void {
  ring.init();
  button1.init();
  button2.init();
  trailingEffect.init(colorGenerator2, 8, 8);
}

auto TimerDemo::update() -> void {
  button1.update();
  button2.update();
  trailingEffect.update();
}

auto TimerDemo::draw() -> void {
  ring.clear();
  trailingEffect.draw(ring);
  ring.show();
}

auto TimerDemo::destroy() -> void {
  Timer::Cancel(timerId);
}

auto TimerDemo::setOn(bool value) -> void {
  this->on = value;
}