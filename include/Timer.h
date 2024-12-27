//
// Created by Brandon on 12/24/24.
//

#ifndef NEOPIXELS_TIMER_H
#define NEOPIXELS_TIMER_H

#include "Types.h"
#include "TimerId.h"
#include "TimerAction.h"
#include "TimerNodePool.h"

class Timer {
public:
  static auto SetTimeout(u32 time, TimerAction& action) -> TimerId;
  static auto Cancel(TimerId id) -> void;
  static auto Update() -> void;

private:
  Timer();
  static auto Instance() -> Timer&;

  TimerNodePool<20> nodePool;
  u16 nextVersion;
  TimerNode* head;
  TimerNode* queue;

  auto setTimeout(u32 time, TimerAction& action) -> TimerId;
  auto setInterval(u32 time, TimerAction& action, i16 repeats) -> TimerId;
  auto update() -> void;
  auto pop(u32 time) -> TimerNode*;

  auto processInserts() -> void;
  auto processDeletes() -> void;
  auto enqueue(TimerNode* node) -> void;
  auto insert(TimerNode* node) -> void;
  auto createNode() -> TimerNode*;
};

#endif //NEOPIXELS_TIMER_H
