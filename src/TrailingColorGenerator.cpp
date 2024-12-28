//
// Created by Brandon on 12/26/24.
//

#include "TrailingColorGenerator.h"
#include "Color.h"

auto TrailingColorGenerator::generate(u32 time) -> Color {
  return generate(time, 0, 0, 0);
}