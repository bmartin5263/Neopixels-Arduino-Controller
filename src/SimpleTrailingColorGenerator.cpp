//
// Created by Brandon on 12/26/24.
//

#include "SimpleTrailingColorGenerator.h"
#include "Color.h"

SimpleTrailingColorGenerator::SimpleTrailingColorGenerator(ColorGenerator* delegate) :
  delegate(delegate)
{}

auto SimpleTrailingColorGenerator::generate(u32 time, u8 offset, u8 phase, u8 speed) -> Color {
  return generate(time);
}

auto SimpleTrailingColorGenerator::generate(u32 time) -> Color {
  return delegate->generate(time);
}