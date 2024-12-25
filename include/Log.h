//
// Created by Brandon on 12/8/24.
//

#ifndef NEOPIXELS_LOG_H
#define NEOPIXELS_LOG_H

#include <Arduino.h>

class Log {
public:

  static auto init() -> void {
    Serial.begin(9600);
  }

  static auto infoLn(const char* msg) -> void {
    Serial.println(msg);
  }

  static auto info(const char* msg) -> void {
    Serial.print(msg);
  }

  static auto infoLn(int msg) -> void {
    Serial.println(msg);
  }

  static auto info(int msg) -> void {
    Serial.print(msg);
  }

};

#endif //NEOPIXELS_LOG_H
