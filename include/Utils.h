//
// Created by Brandon on 12/25/24.
//

#ifndef NEOPIXELS_UTILS_H
#define NEOPIXELS_UTILS_H

#include "Types.h"

#define MAX(a, b) \
    ({ auto _a = (a); auto _b = (b); _a > _b ? _a : _b; })

#define MIN(a, b) \
    ({ auto _a = (a); auto _b = (b); _a < _b ? _a : _b; })

void extractBytes(u32 input, u8& byte0, u8& byte1, u8& byte2, u8& byte3);

#endif //NEOPIXELS_UTILS_H
