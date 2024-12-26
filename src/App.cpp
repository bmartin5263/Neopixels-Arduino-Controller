//
// Created by Brandon on 12/26/24.
//

#include "App.h"
#include "Clocks.h"

auto App::init() -> void {
  Log::Init();
  demo.init();
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