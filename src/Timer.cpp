//
// Created by Brandon on 12/24/24.
//

#include "Assert.h"
#include "Timer.h"
#include "Log.h"
#include "Clocks.h"

Timer::Timer(): nodePool(), nextVersion(0), head(nullptr), queue(nullptr) {
  nodePool.init();
}

auto Timer::Instance() -> Timer& {
  static Timer instance;
  return instance;
}

auto Timer::SetTimeout(u32 time, TimerAction& action) -> TimerId {
  return Instance().setTimeout(time, action);
}

auto Timer::Cancel(TimerId id) -> void {
  if (id.pimpl == nullptr) {
    return;
  }

  auto* node = static_cast<TimerNode*>(id.pimpl);
  if (node->version != id.version) {
    return;
  }

  node->cancelled = true;

  Log::Info("Cancelling TimerNode(executeAt=");
  Log::Info(node->executeAt);
  Log::Info(", version=");
  Log::Info((long) node->version);
  Log::Info(", id=");
  Log::Info((unsigned long) &node);
  Log::InfoLn(")");
}

auto Timer::Update() -> void {
  Instance().update();
}

auto Timer::update() -> void {
  processInserts();

  auto now = Clocks::GlobalTime();
  auto current = pop(now);
  while (current != nullptr) {
    if (current->cancelled) {
      nodePool.destroy(current);
    }
    else {
      Log::Info("Executing Node with Time ");
      Log::Info(current->executeAt);
      Log::Info(" At ");
      Log::InfoLn(now);
      current->execute(now);
      nodePool.destroy(current);
    }

    current = pop(now);
  }
}

auto Timer::setTimeout(u32 time, TimerAction& action) -> TimerId {
  auto currentTime = Clocks::GlobalTime();
  auto executeAt = currentTime + time;
  auto node = createNode();
  if (node == nullptr) {
    return {nullptr, 0};
  }

  ASSERT(node->next == nullptr, "next is not null");
  ASSERT(node->prev == nullptr, "prev is not null");

  node->action = &action;
  node->executeAt = executeAt;
  node->version = nextVersion++;

  enqueue(node);

  return {node, node->version};
}

auto Timer::createNode() -> TimerNode* {
  auto node = nodePool.create();
  if (node == nullptr) {
    processDeletes();
    node = nodePool.create();
    ASSERT(node != nullptr, "new node is null");
  }
  return node;
}

auto Timer::pop(u32 time) -> TimerNode* {
  if (head == nullptr) {
    return nullptr;
  }

  auto result = head;
  if (time >= result->executeAt) {
    head = head->next;
    result->detach();
    return result;
  }

  return nullptr;
}

auto Timer::enqueue(TimerNode* node) -> void {
  Log::Info("Enqueueing TimerNode(executeAt=");
  Log::Info(node->executeAt);
  Log::Info(", version=");
  Log::Info((long) node->version);
  Log::Info(", id=");
  Log::Info((unsigned long) &node);
  Log::InfoLn(")");
  node->next = queue;
  queue = node;
}

auto Timer::processInserts() -> void {
  if (queue == nullptr) {
    return;
  }

  auto current = queue;
  while (current != nullptr) {
    auto next = current->next;
    current->detach();
    insert(current);
    current = next;
  }

  queue = nullptr;
}

auto Timer::insert(TimerNode* newNode) -> void {
  // If the list is empty, make the new newNode the head
  Log::Info("Inserting TimerNode(executeAt=");
  Log::Info(newNode->executeAt);
  Log::Info(", version=");
  Log::Info((long) newNode->version);
  Log::Info(", id=");
  Log::Info((unsigned long) &newNode);
  Log::InfoLn(")");
  if (head == nullptr) {
    Log::InfoLn("Inserted into empty list");
    head = newNode;
    return;
  }

  // If the new newNode has higher priority (lower value) than the head
  if (newNode->executeAt < head->executeAt) {
    Log::InfoLn("Inserted as new head");
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    return;
  }

  // Traverse to find the correct position
  auto current = head;
  while (current->next != nullptr && current->next->executeAt <= newNode->executeAt) {
    current = current->next;
  }

  // Insert the new newNode in the correct position
  Log::Info("Inserted after ");
  Log::InfoLn(current->executeAt);

  newNode->next = current->next;
  if (current->next != nullptr) {
    current->next->prev = newNode;
  }
  current->next = newNode;
  newNode->prev = current;
}

auto Timer::processDeletes() -> void {
  Log::Info("Processing Deleted Timers");
  while (head != nullptr && head->cancelled) {
    auto toDelete = head;
    head = toDelete->next;
    toDelete->detach();
    nodePool.destroy(toDelete);
  }

  if (head == nullptr) {
    return;
  }

  auto current = head->next;
  while (current != nullptr) {
    if (current->cancelled) {
      auto toDelete = current;
      current = toDelete->next;
      toDelete->detach();
      nodePool.destroy(toDelete);
    }
    else {
      current = current->next;
    }
  }
}