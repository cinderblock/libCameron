
#include "BitBangMasterSPI.hpp"

using namespace libCameron;

using Basic::u1;

template <class MOSI, class MISO, class SCLK, bool CPOL_, bool CPHA_, unsigned int halfBitPeriodClockCycles>
BitBangMasterSPI<MOSI, MISO, SCLK, CPOL_, CPHA_, halfBitPeriodClockCycles>::BitBangMasterSPI() {
  // static_assert(typeof MOSI == IOpin, "Must specialize template with IOpin references")

  MOSI::set(0);
  clkIdle();

  MOSI::output();
  SCLK::output();
  MISO::input();
};

template <class MOSI, class MISO, class SCLK, bool CPOL_, bool CPHA_, unsigned int halfBitPeriodClockCycles>
u1 BitBangMasterSPI<MOSI, MISO, SCLK, CPOL_, CPHA_, halfBitPeriodClockCycles>::send(u1 byte) {
  u1 i = 8;

  do {
    bool temp = sendBit(byte & (1 << 7));
    byte <<= 1;
    if (temp) byte |= temp;
  } while (--i);

  return byte;
}

template <class MOSI, class MISO, class SCLK, bool CPOL_, bool CPHA_, unsigned int halfBitPeriodClockCycles>
void BitBangMasterSPI<MOSI, MISO, SCLK, CPOL_, CPHA_, halfBitPeriodClockCycles>::send(u1 const *out, u1 num, u1 *dest) {
  while (num) {
    *dest++ = send(*out++);
    num--;
  }
}
