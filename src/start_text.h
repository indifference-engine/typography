#ifndef START_TEXT_H

#define START_TEXT_H

#include "text_state.h"

/**
 * Initializes state to start producing an item of text.
 * @param number_of_writable_code_points The maximum number of code points which
 *                                       can be written.
 * @param written_glyph_indices Tracks the glyph indices which have been written
 *                              so far.
 * @return The initialized state.
 */
text_state start_text(
    const int number_of_writable_code_points,
    int *const written_glyph_indices);

#endif
