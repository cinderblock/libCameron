#pragma once

#include "basicTypes.hpp"

namespace libCameron {

using Basic::s1;
using Basic::s2;
using Basic::s4;
using Basic::u1;
using Basic::u2;
using Basic::u4;

class DecPrintFormatter {
private:
  void (*const destination)(u1 const byte);

public:
  DecPrintFormatter(void (*const dest)(u1 const byte));

  void print(u1 const byte) { print((u2)byte); }
  void print(u2 const word);
  void print(u4 const dword);

  void print(s1 const byte);
  void print(s2 const word);
  void print(s4 const dword);

  void print(char const *str);

  inline void print(const bool bl) { print(bl ? '1' : '0'); }

  inline void print(char c) { destination(c); }

  inline DecPrintFormatter &operator<<(const bool bl) {
    print(bl);
    return *this;
  }

  inline DecPrintFormatter &operator<<(const char c) {
    print(c);
    return *this;
  }

  inline DecPrintFormatter &operator<<(const u1 byte) {
    print(byte);
    return *this;
  }
  inline DecPrintFormatter &operator<<(const u2 word) {
    print(word);
    return *this;
  }
  inline DecPrintFormatter &operator<<(const u4 word) {
    print(word);
    return *this;
  }

  inline DecPrintFormatter &operator<<(const s1 byte) {
    print(byte);
    return *this;
  }
  inline DecPrintFormatter &operator<<(const s2 word) {
    print(word);
    return *this;
  }
  inline DecPrintFormatter &operator<<(const s4 word) {
    print(word);
    return *this;
  }

  inline DecPrintFormatter &operator<<(char const *str) {
    print(str);
    return *this;
  }

  inline DecPrintFormatter &operator<<(DecPrintFormatter &(*const func)(DecPrintFormatter &)) { return func(*this); }
  inline DecPrintFormatter &operator<<(void (*const func)(DecPrintFormatter &)) {
    func(*this);
    return *this;
  }

private:
  inline static const u1 dec(u1 const c) {
    if (c < 10) return c + '0';
    return ' ';
  }
};

}; // namespace libCameron
