#pragma once

#include <AVR++/basicTypes.hpp>

namespace libCameron {

using Basic::u1;

template <typename Type, bool readInterrupt, bool writeInterrupt = !readInterrupt>
class TripleBuffer {

  // The three buffers of the Triple Buffer

  /**
   * The RED buffer
   */
  Type rBuffer;

  /**
   * The GREEN buffer
   */
  Type gBuffer;

  /**
   * The BLUE buffer
   */
  Type bBuffer;

  /**
   * All possible buffer states.
   *
   * @See Triple Buffer state machine diagram
   */
  enum class State : u1 { A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P };

  /**
   * The
   */
  State state;

public:
  inline TripleBuffer() : state(State::A) {}

  /**
   * Reserve the newest block for reading
   * @return
   */
  void reserveNewestBufferForReading();

  /**
   * Mark the buffer the writer is using as the newest, indicating that data is
   * available and allowing the reader to access the next block
   * @return
   */
  void markNewestBuffer();

  /**
   * Check if there is new data available for the reader side
   * @return
   */
  bool isNewData();

  /**
   * Get the buffer that should be written to
   * @return
   */
  Type *getWriteBuffer();

  /**
   * Get the buffer that should be read from
   * @return
   */
  Type *getReadBuffer();
};
}; // namespace libCameron
