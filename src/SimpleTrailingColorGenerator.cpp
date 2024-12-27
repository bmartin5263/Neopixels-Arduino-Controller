//
// Created by Brandon on 12/26/24.
//

#include "SimpleTrailingColorGenerator.h"
#include "Color.h"

SimpleTrailingColorGenerator::SimpleTrailingColorGenerator(ColorGenerator* delegate) :
  delegate(delegate)
{}

auto SimpleTrailingColorGenerator::generate(u32 time, NeopixelLine* line, u8 pixel) -> Color {
  return generate(time);
}

auto SimpleTrailingColorGenerator::generate(long time) -> Color {
  return delegate->generate(time);
}