//
// Created by Brandon on 12/25/24.
//

#include "Clocks.h"
#include "Log.h"
#include "Arduino.h"

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

auto Clocks::GlobalFps() -> u32 {
  return Instance().globalFps();
}

auto Clocks::globalTime() -> u32 {
  return global;
}

auto Clocks::globalFps() -> u32 {
  return fps;
}

auto Clocks::nextTick() -> void {
  auto currentTime = millis();
  auto elapsed = currentTime - lastTimeMs;

  if (elapsed >= 1000) { // Update every second
    Log::Info("FPS: ");
    Log::InfoLn(globalFpsCounter);

    globalFpsCounter = 0;
    lastTimeMs = currentTime;
  }

  ++globalFpsCounter;
  ++global;
}
