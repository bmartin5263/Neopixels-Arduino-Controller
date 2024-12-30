//
// Created by Brandon on 12/27/24.
//

#include "TimerDemo.h"
#include "Timer.h"
#include "Utils.h"
#include "Clocks.h"

class MyGenerator : public TrailingColorGenerator {
public:
  auto generate(u32 time, u8 length, u8 offset, u16 phase, u8 speed) -> Color override {
    if (offset < 8) {
      return Color::GREEN(speed == 0 ? 255 : 40);
    }
    if (offset < 10) {
      return Color::YELLOW(speed == 0 ? 255 : 40);
    }
    else {
      return Color::RED(speed == 0 ? 255 : 40);
    }
  }
};

static auto red = StaticColorGenerator(Color::GREEN());
static auto green = StaticColorGenerator(Color::GREEN());
static auto myGenerator = MyGenerator();

auto TimerDemo::init() -> void {
  ring.init();
  ring.reverse();
  button1.init();
  button2.init();
  trailingEffect.init(red, 2, 10);
  trailingEffect2.init(green, 2, 10, 8);
  fillEffect
      .setColorGenerator(myGenerator)
      .setLength(5)
      .setOffset(2);
}

auto TimerDemo::update() -> void {
  button1.update();
  button2.update();
  trailingEffect.update();
  trailingEffect2.update();
}

auto TimerDemo::draw() -> void {
  ring.clear();

  // RGB effect
//  auto v = 1.0 / 16;
//  for (int i = 0; i < 16; ++i) {
//    ring[i] = Color::HslToRgb(Clamp(v * i + (Clocks::GlobalTime() * .002)));
//  }
 for (int i = 2; i < 14; ++i) {
    ring[i] = myGenerator.generate(0, 16, i - 2, 0, 1);
  }

  auto b = Color::FloatToByte(Sigmoid(Clocks::GlobalTime() * 2), 13);
  fillEffect.setLength(b);
  fillEffect.draw(ring);

  ring[0] = Color::OFF();
  ring[1] = Color::OFF();
  ring[14] = Color::OFF();
  ring[15] = Color::OFF();

//  auto x = Color::FloatToByte(Sigmoid(Clocks::GlobalTime() * 4));
//
//  red.setColor(Color::MAGENTA()
//      .greenShift(x)
//      .blueShift(-x)
//      .redShift(-x)
//  );
//  green.setColor(Color::MAGENTA()
//      .greenShift(x)
//      .redShift(-x)
//      .blueShift(-x)
//  );
//
//  trailingEffect.draw(ring);
//  trailingEffect2.draw(ring);

  ring.show();
}

auto TimerDemo::destroy() -> void {
  Timer::Cancel(timerId);
}

auto TimerDemo::setOn(bool value) -> void {
  this->on = value;
}