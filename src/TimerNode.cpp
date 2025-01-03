//
// Created by Brandon on 12/27/24.
//

#include "TimerNode.h"
#include "TimerAction.h"

auto TimerNode::detach() -> void {
  if (next != nullptr) {
    next->prev = prev;
  }
  if (prev != nullptr) {
    prev->next = next;
  }
  next = nullptr;
  prev = nullptr;
}

auto TimerNode::execute(u32 time) -> void {
  action->execute({this, version}, time);
}

auto TimerNode::reset() -> void {
  next = nullptr;
  prev = nullptr;
  cancelled = false;
  action = nullptr;
  version = 0;
  executeAt = INT32_MAX;
}