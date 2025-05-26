#ifndef WRITE_TEXT_CODE_POINT_H

#define WRITE_TEXT_CODE_POINT_H

#include <stdbool.h>
#include <stdint.h>
#include "text_state.h"

/**
 * Appends a code point to an item of text being composed.
 * @param code_point The UTF-32 code point to append.
 * @param text_state The state to append to.
 * @return True when the operation succeeds, otherwise, false.  The state given
 *         must be started again before it can be used again.
 */
bool write_text_code_point(
    const uint32_t code_point,
    text_state *const text_state);

#endif
