#pragma once

#include "basicTypes.hpp"
#include <avr/pgmspace.h>

namespace libCameron {

using Basic::u1;

class CRC8 {
  u1 crc;
  static const u1 table[256] PROGMEM;

public:
  inline void reset() { crc = 0; }

  inline CRC8() { reset(); }

  inline void feed(u1 b) { crc = pgm_read_byte(&table[crc ^ b]); }

  inline u1 getCRC() { return crc; }

  inline CRC8 &operator<<(u1 b) {
    feed(b);
    return *this;
  }
};

}; // namespace libCameron
