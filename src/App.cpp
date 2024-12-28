//
// Created by Brandon on 12/26/24.
//

#include "Assert.h"
#include "App.h"
#include "Clocks.h"
#include "Log.h"
#include "Timer.h"

auto App::init() -> void {
  Log::Init();
  demo.init();

  Log::Info("sizeof(int) = ");
  Log::InfoLn((unsigned long) sizeof(int));
  Log::Info("sizeof(long) = ");
  Log::InfoLn((unsigned long) sizeof(long));
  Log::Info("sizeof(long long) = ");
  Log::InfoLn((unsigned long) sizeof(long long));
  Log::Info("sizeof(App*) = ");
  Log::InfoLn((unsigned long) sizeof(App*));
  Log::Info("sizeof(App) = ");
  Log::InfoLn((unsigned long) sizeof(App));
  Log::InfoLn((unsigned long) sizeof(Timer));
  Log::InfoLn((unsigned long) sizeof(TimerNode));
}

auto App::loop() -> void {
  update();
  draw();
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