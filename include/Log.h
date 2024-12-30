//
// Created by Brandon on 12/8/24.
//

#ifndef NEOPIXELS_LOG_H
#define NEOPIXELS_LOG_H

#include <Arduino.h>

class Log {
public:

  static auto Init(unsigned long baud = 9600) -> void {
    Serial.begin(baud);
  }

  static auto InfoLn(const char* msg) -> void {
    Serial.println(msg);
  }

  static auto Info(const char* msg) -> void {
    Serial.print(msg);
  }

  static auto InfoLn(long msg) -> void {
    Serial.println(msg);
  }

  static auto Info(long msg) -> void {
    Serial.print(msg);
  }

  static auto InfoLn(float msg) -> void {
    Serial.println(msg);
  }

  static auto Info(float msg) -> void {
    Serial.print(msg);
  }

  static auto InfoLn(unsigned long msg) -> void {
    Serial.println(msg);
  }

  static auto Info(unsigned long msg) -> void {
    Serial.print(msg);
  }

};

#endif //NEOPIXELS_LOG_H
