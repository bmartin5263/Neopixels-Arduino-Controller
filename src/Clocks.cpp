//
// Created by Brandon on 12/25/24.
//

#include "Clocks.h"

Clocks& Clocks::Instance() {
  static Clocks instance;
  return instance;
}

auto Clocks::NextTick() -> void {
  Instance().nextTick();
}

auto Clocks::GlobalTime() -> long {
  return Instance().globalTime();
}

auto Clocks::globalTime() -> long {
  return global;
}

auto Clocks::nextTick() -> void {
  global += 1;
}
