//
// Created by Brandon on 12/27/24.
//

#ifndef NEOPIXELS_ASSERT_H
#define NEOPIXELS_ASSERT_H

#include "Log.h"

//#ifndef NDEBUG
#define ASSERT(condition, message) \
        do { \
            if (!(condition)) {    \
                Log::InfoLn("Assertion failed: (" #condition ")"); \
                Log::Info("File: "); \
                Log::Info(__FILE__); \
                Log::Info(", Line: "); \
                Log::InfoLn((unsigned long) __LINE__); \
                Log::Info("Message: "); \
                Log::InfoLn(message); \
            } \
        } while (false)
//#else
//#define ASSERT(condition, message) ((void)0) // No-op in release builds
//#endif

#endif //NEOPIXELS_ASSERT_H
