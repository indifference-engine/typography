#include <stdbool.h>
#include "written_text.h"
#include "measure_text_height.h"

int measure_text_height(const written_text written_text)
{
  int total_height = 0;
  int height_of_previous_line = 0;
  int height_of_current_line = 0;
  int line_spacing_of_previous_line = 0;
  int line_spacing_of_current_line = 0;
  int number_of_banked_lines = 0;
  bool has_written_on_this_line = false;
  bool first_line = true;

  for (int code_point_index = 0; code_point_index < written_text.number_of_written_code_points; code_point_index++)
  {
    const int glyph_index = written_text.written_glyph_indices[code_point_index];

    if (glyph_index == -1)
    {
      if (has_written_on_this_line)
      {
        total_height += number_of_banked_lines * (line_spacing_of_previous_line > line_spacing_of_current_line ? line_spacing_of_previous_line : line_spacing_of_current_line);
        total_height += (number_of_banked_lines - (first_line ? 0 : 1)) * (height_of_previous_line > height_of_current_line ? height_of_previous_line : height_of_current_line);
        total_height += height_of_current_line;
        height_of_previous_line = height_of_current_line;
        height_of_current_line = 0;
        line_spacing_of_previous_line = line_spacing_of_current_line;
        line_spacing_of_current_line = 0;
        number_of_banked_lines = 1;
        has_written_on_this_line = false;
        first_line = false;
      }
      else
      {
        number_of_banked_lines++;
      }
    }
    else
    {
      has_written_on_this_line = true;

      const text_font *const text_font = written_text.written_text_fonts[code_point_index];

      if (text_font->line_height > height_of_current_line)
      {
        height_of_current_line = text_font->line_height;
      }

      if (text_font->line_spacing > line_spacing_of_current_line)
      {
        line_spacing_of_current_line = text_font->line_spacing;
      }
    }
  }

  if (number_of_banked_lines > 0) {
    if (has_written_on_this_line) {
      total_height += number_of_banked_lines * (line_spacing_of_previous_line > line_spacing_of_current_line ? line_spacing_of_previous_line : line_spacing_of_current_line);
      total_height += (number_of_banked_lines - (first_line ? 0 : 1)) * (height_of_previous_line > height_of_current_line ? height_of_previous_line : height_of_current_line);
      total_height += height_of_current_line;
    } else {
      total_height += number_of_banked_lines * line_spacing_of_previous_line;
      total_height += number_of_banked_lines * height_of_previous_line;
    }
  }

  return total_height;
}
