#ifndef TEXT_FONT_H

#define TEXT_FONT_H

#include <stdint.h>

/**
 * A collection of glyphs forming a font.
 */
typedef struct
{
  /**
   * The number of columns between each code point.
   */
  const int code_point_spacing;

  /**
   * The number of rows between each line.
   */
  const int line_spacing;

  /**
   * The height of a line (typically that of a capital letter lacking
   * descenders).
   */
  const int line_height;

  /**
   * The widths of the glyphs in columns.
   */
  const int *const glyph_widths;

  /**
   * The code points of the glyphs.
   */
  const uint32_t *const glyph_code_points;

  /**
   * THe number of glyphs.
   */
  const int number_of_glyphs;
} text_font;

#endif
