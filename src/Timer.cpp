//
// Created by Brandon on 12/24/24.
//

#include "Timer.h"

Timer& Timer::Instance() {
  static Timer instance;
  return instance;
}

auto Timer::SetTimeout(int time, Callable action) -> TimerId {
  return Instance().setTimeout(time, action);
}

auto Timer::SetInterval(int time, Callable action) -> TimerId {
  return Instance().setInterval(time, action);
}

auto Timer::Cancel(TimerId id) -> void {
  Instance().cancel(id);
}

auto Timer::Update() -> void {
  Instance().update();
}

auto Timer::update() -> void {

}