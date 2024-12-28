//
// Created by Brandon on 12/26/24.
//

#ifndef NEOPIXELS_TIMERNODEPOOL_H
#define NEOPIXELS_TIMERNODEPOOL_H

#include "Assert.h"
#include "TimerNode.h"

template <int N>
class TimerNodePool {
public:
  auto init() -> void {
    for (int i = 0; i < N; ++i) {
      TimerNode& current = pool[i];
      if (i > 0) {
        current.prev = &pool[i - 1];
      }
      if (i < N - 1) {
        current.next = &pool[i + 1];
      }
    }

    for (int i = 0; i < N; ++i) {
      TimerNode& current = pool[i];
      if (i > 0) {
        ASSERT(current.prev == &pool[i - 1], "prev not set");
      }
      else {
        ASSERT(current.prev == nullptr, "prev is set");
      }
      if (i < N - 1) {
        ASSERT(current.next == &pool[i + 1], "prev not set");
      }
      else {
        ASSERT(current.next == nullptr, "prev is set");
      }
    }

    head = &pool[0];
  }

  auto create() -> TimerNode* {
    ASSERT(head != nullptr, "head of node pool os null");
    auto result = head;
    head = head->next;
    result->detach();
    return result;
  }

  auto destroy(TimerNode* node) -> void {
    node->reset();
    node->next = head;
    head = node;
  }

private:
  TimerNode pool[N];
  TimerNode* head{};
};

#endif //NEOPIXELS_TIMERNODEPOOL_H
