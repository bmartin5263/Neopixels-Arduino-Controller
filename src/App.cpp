//
// Created by Brandon on 12/26/24.
//

#include "Assert.h"
#include "App.h"
#include "Clocks.h"
#include "Log.h"
#include "Timer.h"
#include "Utils.h"

auto App::init() -> void {
  Log::Init();
  demo.init();

  Log::Info("System Info{");
  Log::Info("sizeof(int) = ");
  Log::Info((unsigned long) sizeof(int));
  Log::Info(", sizeof(long) = ");
  Log::Info((unsigned long) sizeof(long));
  Log::Info(", sizeof(long long) = ");
  Log::Info((unsigned long) sizeof(long long));
  Log::Info(", sizeof(void*) = ");
  Log::Info((unsigned long) sizeof(void*));
  Log::Info(", sizeof(App) = ");
  Log::Info((unsigned long) sizeof(App));
  Log::InfoLn("}");

}

auto App::loop() -> void {
  auto start = millis();

  update();
  draw();

  auto stop = millis();
  auto time = stop - start;
  i32 max = MAX_MS - time;
  auto sleep = MAX(max, 0u);
  delay(sleep);
}

auto App::update() -> void {
  updateSubsystems();
  demo.update();
}

auto App::draw() -> void {
  demo.draw();
}

auto App::updateSubsystems() -> void {
  Clocks::NextTick();
  Timer::Update();
}