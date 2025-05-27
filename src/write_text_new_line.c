#include <stdbool.h>
#include "written_text.h"
#include "write_text_code_point.h"
#include "write_text_new_line.h"

bool write_text_new_line(
    const text_font *const text_font,
    written_text *const written_text)
{
  const int number_of_written_code_points = written_text->number_of_written_code_points;

  if (number_of_written_code_points == written_text->number_of_writable_code_points)
  {
    return false;
  }

  written_text->written_text_fonts[number_of_written_code_points] = text_font;
  written_text->written_glyph_indices[number_of_written_code_points] = -1;
  written_text->number_of_written_code_points = number_of_written_code_points + 1;
  return true;
}
