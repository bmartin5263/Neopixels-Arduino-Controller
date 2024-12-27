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
}

auto TimerDemo::update() -> void {
  button1.update();
  button2.update();

  if (button1.getState() == ButtonState::PRESS) {
    setOn(true);
    timerId = Timer::SetTimeout(3000, action);
  }
  if (button2.getState() == ButtonState::PRESS) {
    Timer::Cancel(timerId);
  }
}

auto TimerDemo::draw() -> void {
  ring.clear();
  if (on) {
    ring.setColor(0, Color::RED());
  }
  ring.show();
}

auto TimerDemo::destroy() -> void {
  Timer::Cancel(timerId);
}

auto TimerDemo::setOn(bool value) -> void {
  this->on = value;
}

auto Action::execute(TimerId timerId, u32 globalTime) -> void {
  demo->setOn(false);
}

Action::Action(TimerDemo* demo) : demo(demo) {}
