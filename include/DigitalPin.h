//
// Created by Brandon on 12/8/24.
//

#ifndef NEOPIXELS_DIGITALPIN_H
#define NEOPIXELS_DIGITALPIN_H

class DigitalPin {
public:
  DigitalPin(int number);
  void open(int mode) const;
  bool read() const;
  int number() const;

private:
  int _number;
};

#endif //NEOPIXELS_DIGITALPIN_H
