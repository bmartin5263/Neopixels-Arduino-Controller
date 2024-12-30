//
// Created by Brandon on 12/29/24.
//

#include "ColorGenerator.h"

class DefaultColorGenerator : public ColorGenerator {
public:
  auto generate(u32 time) -> Color {
    return Color::RED();
  }
};

auto ColorGenerator::Default() -> ColorGenerator& {
  static DefaultColorGenerator defaultGenerator;
  return defaultGenerator;
}