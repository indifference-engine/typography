#ifndef START_TEXT_H

#define START_TEXT_H

#include "text_font.h"
#include "written_text.h"

/**
 * Initializes state to start producing an item of text.
 * @param number_of_writable_code_points The maximum number of code points which
 *                                       can be written.
 * @param written_text_fonts Tracks the text fonts of the code points which have
 *                           been written so far.
 * @param written_glyph_indices Tracks the glyph indices which have been written
 *                              so far.
 * @param written_opacities Tracks the opacities of the code points which have
 *                          been written so far.
 * @param written_reds Tracks the red intensities of the code points which
 *                     have been written so far.
 * @param written_greens Tracks the green intensities of the code points which
 *                       have been written so far.
 * @param written_blues Tracks the blue intensities of the code points which
 *                      have been written so far.
 * @return The initialized state.
 */
written_text start_text(
    const int number_of_writable_code_points,
    const text_font **const written_text_fonts,
    int *const written_glyph_indices,
    float *const written_opacities,
    float *const written_reds,
    float *const written_greens,
    float *const written_blues);

#endif
