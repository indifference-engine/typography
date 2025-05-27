#ifndef PLACED_TEXT_H

#define PLACED_TEXT_H

#include "text_font.h"

/**
 * State which tracks the creation of an item of text.
 */
typedef struct
{
  /**
   * The number of code points which have been placed.
   */
  int number_of_placed_glyphs;

  /**
   * The maximum number of glyphs which can be placed.
   */

  const int number_of_placeable_glyphs;

  /**
   * The indices of the glyphs which have been placed.
   */
  int *const placed_glyph_indices;

  /**
   * The number of rows that each glyph is placed below the anchor.
   */
  int *const placed_glyph_rows;

  /**
   * The number of columns that each glyph is placed right of the anchor.
   */
  int *const placed_glyph_columns;
} placed_text;

#endif
