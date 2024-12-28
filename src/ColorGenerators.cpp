//
// Created by Brandon on 12/27/24.
//

#include "ColorGenerators.h"
#include "Log.h"

auto BlueRedGenerator::generate(u32 time, u8 length, u8 offset, u16 phase, u8 speed) -> Color {
  return {static_cast<u8>(255 - offset * 31), 0, static_cast<u8>(offset * 31)};
}

auto RainbowGenerator::generate(u32 time, u8 length, u8 offset, u16 phase, u8 speed) -> Color {
  auto t = time;
  auto h = (t % 256) / 255.0;
//  Log::Info((unsigned long) offset);
//  Log::Info(" / ");
//  Log::Info((unsigned long) length);
//  Log::Info(" = ");
  auto a = (double) offset / length;
//  Log::InfoLn(a);
  auto o = a + h;
//  Log::Info(o);
  auto x = Color::HslToRgb(o, 1.0, .5);
//  Log::Info(" = good");
  return x;
}