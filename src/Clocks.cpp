//
// Created by Brandon on 12/25/24.
//

#include "Clocks.h"
#include "Log.h"

Clocks& Clocks::Instance() {
  static Clocks instance;
  return instance;
}

auto Clocks::NextTick() -> void {
  Instance().nextTick();
}

auto Clocks::GlobalTime() -> u32 {
  return Instance().globalTime();
}

auto Clocks::globalTime() -> u32 {
  return global;
}

auto Clocks::nextTick() -> void {
  global += 1;
  if ((global % 1000) == 0) {
    Log::Info("Ticks: ");
    Log::InfoLn(global);
  }
}
