//
// Created by Brandon on 12/26/24.
//

#include "TrailingColorGenerator.h"
#include "Color.h"

class DefaultTrailingColorGenerator : public TrailingColorGenerator {
public:
  auto generate(u32 time, u8 length, u8 offset, u16 phase, u8 speed) -> Color {
    return Color::RED();
  }
};


auto TrailingColorGenerator::generate(u32 time) -> Color {
  return generate(time, 0, 0, 0, 0);
}

auto TrailingColorGenerator::Default() -> TrailingColorGenerator& {
  static DefaultTrailingColorGenerator defaultGenerator;
  return defaultGenerator;
}