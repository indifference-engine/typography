#ifndef WRITTEN_TEXT_H

#define WRITTEN_TEXT_H

#include "text_font.h"

/**
 * State which tracks the creation of an item of text.
 */
typedef struct
{
  /**
   * The number of code points which have been written so far.
   */
  int number_of_written_code_points;

  /**
   * Tracks the text fonts of the code points which have been written so far.
   */
  const text_font **const written_text_fonts;

  /**
   * The maximum number of code points which can be written.
   */
  const int number_of_writable_code_points;

  /**
   * Tracks the glyph indices which have been written so far.
   */
  int *const written_glyph_indices;

  /**
   * Tracks the opacities of the code points which have been written so far.
   */
  float *const written_opacities;

  /**
   * Tracks the red intensities of the code points which have been written so
   * far.
   */
  float *const written_reds;

  /**
   * Tracks the green intensities of the code points which have been written so
   * far.
   */
  float *const written_greens;

  /**
   * Tracks the blue intensities of the code points which have been written so
   * far.
   */
  float *const written_blues;
} written_text;

#endif
