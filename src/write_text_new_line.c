#include <stdbool.h>
#include "written_text.h"
#include "write_text_code_point.h"
#include "write_text_new_line.h"

bool write_text_new_line(written_text *const written_text)
{
  const int number_of_written_code_points = written_text->number_of_written_code_points;

  if (number_of_written_code_points == written_text->number_of_writable_code_points)
  {
    return false;
  }

  written_text->written_glyph_indices[number_of_written_code_points] = -1;
  written_text->number_of_written_code_points = number_of_written_code_points + 1;
  return true;
}
