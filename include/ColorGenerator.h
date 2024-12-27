//
// Created by Brandon on 12/26/24.
//

#ifndef NEOPIXELS_COLORGENERATOR_H
#define NEOPIXELS_COLORGENERATOR_H

class Color;
class ColorGenerator {
public:
  virtual auto generate(long time) -> Color = 0;
  virtual ~ColorGenerator() = default;
};

#endif //NEOPIXELS_COLORGENERATOR_H
