#pragma once

#include "basicTypes.hpp"

namespace libCameron {

using Basic::u1;

template <class MOSI, class MISO, class SCLK, bool CPOL_ = false, bool CPHA_ = false,
          unsigned int halfBitPeriodClockCycles = 0>
class BitBangMasterSPI {
  static inline void clkIdle() { SCLK::set(CPOL_); }
  static inline void clkActive() { SCLK::set(!CPOL_); }

  static inline bool sendBit(bool bit) {
    MOSI::set(bit);

    if (!CPHA_) {
      halfBitPeriodDelay();
      clkActive();

      // Technically, SPI says sample MISO before second half delay. Shouldn't matter
      halfBitPeriodDelay();
      u1 ret = MISO::isHigh();

      clkIdle();
      return ret;
    } else {
      clkActive();
      halfBitPeriodDelay();

      // We could possibly wait a little bit and put this read later in the cycle
      u1 ret = MISO::isHigh();
      clkIdle();

      halfBitPeriodDelay();
      return ret;
    }
  }

  static inline void halfBitPeriodDelay() {}

public:
  BitBangMasterSPI();
  static u1 send(u1 data);
  static void send(u1 const *data, u1 num, u1 *dest);
};

}; // namespace libCameron
