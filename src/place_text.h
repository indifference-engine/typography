#ifndef PLACE_TEXT_H

#define PLACE_TEXT_H

#include "text_font.h"
#include "text_state.h"

/**
 * Calculates final co-ordinates for glyphs within an item of text.
 * @param text_font The font to use.
 * @param text_state The text state to place.
 * @param number_of_placeable_glyphs The maximum number of glyphs which can be
 *                                   placed.
 * @param placed_glyph_indices Populated with the indices of the glyphs which
 *                             have been placed when successful.
 * @param placed_glyph_rows Populated with the number of rows that each glyph is
 *                          placed below of the anchor when successful.
 * @param placed_glyph_columns Populated with the number of columns that each
 *                             glyph is placed right of the anchor when
 *                             successful.
 * @return The number of placed glyphs when the operation succeeds.  -1 when the
 *         operation does not succeed.
 */
int place_text(
    const text_font text_font,
    const text_state text_state,
    const int number_of_placeable_glyphs,
    int *const placed_glyph_indices,
    int *const placed_glyph_rows,
    int *const placed_glyph_columns);

#endif
