#include <stdbool.h>
#include <stdint.h>
#include "text_font.h"
#include "written_text.h"
#include "write_text_code_point.h"
#include "write_text_new_line.h"

bool write_text_code_point(
    const uint32_t code_point,
    const text_font *const text_font,
    const float opacity,
    const float red,
    const float green,
    const float blue,
    written_text *const written_text)
{
  if (code_point == 10)
  {
    return write_text_new_line(written_text);
  }

  const int number_of_written_code_points = written_text->number_of_written_code_points;

  if (number_of_written_code_points == written_text->number_of_writable_code_points)
  {
    return false;
  }

  for (int glyph_index = 0; glyph_index < text_font->number_of_glyphs; glyph_index++)
  {
    if (text_font->glyph_code_points[glyph_index] == code_point)
    {
      written_text->written_text_fonts[number_of_written_code_points] = text_font;
      written_text->written_glyph_indices[number_of_written_code_points] = glyph_index;
      written_text->written_opacities[number_of_written_code_points] = opacity;
      written_text->written_reds[number_of_written_code_points] = red;
      written_text->written_greens[number_of_written_code_points] = green;
      written_text->written_blues[number_of_written_code_points] = blue;
      written_text->number_of_written_code_points = number_of_written_code_points + 1;
      return true;
    }
  }

  return false;
}
