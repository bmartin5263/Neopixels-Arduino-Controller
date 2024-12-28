//
// Created by Brandon on 12/25/24.
//

#include "Utils.h"

void extractBytes(int input, u8& byte0, u8& byte1, u8& byte2, u8& byte3) {
  // Extract each byte
  byte0 = (input & 0xFF);        // Extract the least significant byte
  byte1 = (input >> 8) & 0xFF;  // Extract the second byte
  byte2 = (input >> 16) & 0xFF; // Extract the third byte
  byte3 = (input >> 24) & 0xFF; // Extract the most significant byte
}