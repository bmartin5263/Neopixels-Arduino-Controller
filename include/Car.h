//
// Created by Brandon on 12/26/24.
//

#ifndef NCURSES_CAR_H
#define NCURSES_CAR_H

class Car {
public:
  auto accelerate() -> void;
  auto brake() -> void;
  auto update() -> void;
  auto draw() -> void;

  auto getSpeed() -> float const;
  auto getAcceleration() -> float const;

private:
  float speed{};
  float acceleration{};
  float maxAcceleration{};
};

#endif //NCURSES_CAR_H
