#pragma once

/**
 * @brief Some type that can be incremented or decremented and loops to some max (exclusive) (and min (inclusive))
 * value.
 *
 * @tparam T
 * @tparam max The maximum value (exclusive)
 * @tparam min The minimum value (inclusive) (default 0)
 */
template <typename T, T max, T min = 0>
class Looping {
  T i;

public:
  inline constexpr Looping() {}
  inline constexpr Looping(T i) : i(i) {}
  inline T operator++() {
    if (++i == max) i = min;
    return *this;
  }
  inline T operator--() {
    if (i == min) i = max;
    --i;
    return *this;
  }
  template <typename O>
  inline T operator=(O next) {
    while (next > max) next -= max - min;
    while (next < min) next += max - min;
    i = next;
    return *this;
  }
  inline operator T() const { return i; }
  inline T toEnd() const { return max - i; }
};