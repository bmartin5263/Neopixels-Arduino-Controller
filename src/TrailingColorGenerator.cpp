//
// Created by Brandon on 12/26/24.
//

#include "TrailingColorGenerator.h"
#include "Color.h"

auto TrailingColorGenerator::generate(long time) -> Color {
  return generate(time, nullptr, 0);
}