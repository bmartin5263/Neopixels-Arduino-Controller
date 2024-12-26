//
// Created by Brandon on 12/25/24.
//

#ifndef NEOPIXELS_CLOCKS_H
#define NEOPIXELS_CLOCKS_H

class Clocks {
public:
  auto NextTick() -> void;
  auto GlobalTime() -> long;

private:
  long global{};

  auto nextTick() -> void;
  auto globalTime() -> long;

  static Clocks& Instance();
};

#endif //NEOPIXELS_CLOCKS_H
