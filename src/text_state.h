#ifndef TEXT_STATE_H

#define TEXT_STATE_H

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
   * The maximum number of code points which can be written.
   */
  const int number_of_writable_code_points;

  /**
   * Tracks the glyph indices which have been written so far.
   */
  int *const written_glyph_indices;
} text_state;

#endif
