//
// Created by Brandon on 12/26/24.
//

#ifndef NEOPIXELS_TRAILINGCOLORGENERATOR_H
#define NEOPIXELS_TRAILINGCOLORGENERATOR_H

#include "ColorGenerator.h"
#include "Types.h"

class NeopixelLine;
class TrailingColorGenerator : public ColorGenerator {
public:
  auto generate(u32 time) -> Color override;

  /**
   *
   * @param time    current clock time, will always be increasing
   * @param length  how long/big the group of pixels this color generator is working with (0 if not known)
   * @param offset  what position in the group of pixels this color generator is working with (0 if not known)
   * @param phase   phase effect is in (0 if not known)
   * @param speed   how fast the effect is (0 if not known)
   * @return
   */
  virtual auto generate(u32 time, u8 length, u8 offset, u16 phase, u8 speed) -> Color = 0;

  ~TrailingColorGenerator() override = default;

  static auto Default() -> TrailingColorGenerator&;
};

#endif //NEOPIXELS_TRAILINGCOLORGENERATOR_H
