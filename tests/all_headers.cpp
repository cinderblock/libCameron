// Aggregate header-parse test for libCameron. Including every public header
// here catches errors that wouldn't surface without instantiation.

#include "BitBangMasterSPI.hpp"
#include "BlockBuffer.hpp"
#include "CRC8.hpp"
#include "DecPrintFormatter.hpp"
#include "Looper.hpp"
#include "TripleBuffer.hpp"
#include "basicTypes.hpp"

// Touch a few concrete instantiations so template bodies actually get parsed.
namespace {
[[maybe_unused]] inline void touch() {
  libCameron::CRC8 c;
  c.feed(0xAA);
}
} // namespace
