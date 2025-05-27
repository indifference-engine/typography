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

  /**
   * The opacity of each placed glyph.
   */
  float *const placed_glyph_opacities;

  /**
   * The red intensity of each placed glyph.
   */
  float *const placed_glyph_reds;

  /**
   * The green intensity of each placed glyph.
   */
  float *const placed_glyph_greens;

  /**
   * The blue intensity of each placed glyph.
   */
  float *const placed_glyph_blues;
} placed_text;

#endif
