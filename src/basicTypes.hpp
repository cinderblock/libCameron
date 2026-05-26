#pragma once

// Byte-counting aliases for the standard fixed-width integer types: u1 is
// 1 byte, u2 is 2 bytes, etc. — chosen because <stdint.h>'s bit-counting
// names (uint8_t = 8 bits) obscure the actual storage cost on AVR, where
// every byte matters. The same set is also defined in AVR++'s
// AVR++/basicTypes.hpp; the two files must stay in sync on the shared types
// so they can be included together (C++ permits identical typedef
// redeclaration in the same namespace). AVR++ additionally defines u3/s3
// (__uint24/__int24, AVR-gcc extensions) which libCameron doesn't need.
