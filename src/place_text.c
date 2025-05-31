#include "text_font.h"
#include "written_text.h"
#include "placed_text.h"
#include "place_text.h"

static int end_line(
    const int horizontal_alignment,
    placed_text *const placed_text,
    const int height_of_previous_line,
    const int height_of_current_line,
    const int line_spacing_of_previous_line,
    const int line_spacing_of_current_line,
    const int width_of_current_line,
    const int index_of_first_glyph_on_current_line,
    const int number_of_banked_lines)
{
  const int output = height_of_current_line + (line_spacing_of_previous_line > line_spacing_of_current_line ? line_spacing_of_previous_line : line_spacing_of_current_line) * number_of_banked_lines + (height_of_previous_line > height_of_current_line ? height_of_previous_line : height_of_current_line) * (index_of_first_glyph_on_current_line == 0 ? number_of_banked_lines : number_of_banked_lines - 1);

  for (int glyph_index = index_of_first_glyph_on_current_line; glyph_index < placed_text->number_of_placed_glyphs; glyph_index++)
  {
    placed_text->placed_glyph_rows[glyph_index] += output - placed_text->placed_text_fonts[glyph_index]->line_height;
  }

  if (horizontal_alignment != RIGHT_OF_TEXT_ANCHOR)
  {
    const int amount_to_shift = horizontal_alignment == CENTERED_ON_TEXT_ANCHOR ? width_of_current_line / 2 : width_of_current_line;

    for (int glyph_index = index_of_first_glyph_on_current_line; glyph_index < placed_text->number_of_placed_glyphs; glyph_index++)
    {
      placed_text->placed_glyph_columns[glyph_index] -= amount_to_shift;
    }
  }

  return output;
}

int place_text(
    const written_text written_text,
    const int vertical_alignment,
    const int horizontal_alignment,
    placed_text *const placed_text)
{
  int total_height = 0;
  int height_of_previous_line = 0;
  int height_of_current_line = 0;
  int line_spacing_of_previous_line = 0;
  int line_spacing_of_current_line = 0;
  int width_of_current_line = 0;
  int code_point_spacing_of_previous_character = -1;
  int index_of_first_glyph_on_current_line = 0;
  int number_of_banked_lines = 0;

  for (int code_point_index = 0; code_point_index < written_text.number_of_written_code_points; code_point_index++)
  {
    if (written_text.written_glyph_indices[code_point_index] == -1)
    {
      if (index_of_first_glyph_on_current_line == placed_text->number_of_placed_glyphs)
      {
        number_of_banked_lines++;
      }
      else
      {
        total_height += end_line(horizontal_alignment, placed_text, height_of_previous_line, height_of_current_line, line_spacing_of_previous_line, line_spacing_of_current_line, width_of_current_line, index_of_first_glyph_on_current_line, number_of_banked_lines);

        height_of_previous_line = height_of_current_line;
        height_of_current_line = 0;
        line_spacing_of_previous_line = line_spacing_of_current_line;
        line_spacing_of_current_line = 0;
        width_of_current_line = 0;
        code_point_spacing_of_previous_character = -1;
        index_of_first_glyph_on_current_line = placed_text->number_of_placed_glyphs;
        number_of_banked_lines = 1;
      }
    }
    else
    {
      if (placed_text->number_of_placed_glyphs == placed_text->number_of_placeable_glyphs)
      {
        return -1;
      }

      const text_font *const text_font = written_text.written_text_fonts[code_point_index];

      if (code_point_spacing_of_previous_character != -1)
      {
        width_of_current_line += text_font->code_point_spacing > code_point_spacing_of_previous_character ? text_font->code_point_spacing : code_point_spacing_of_previous_character;
      }

      placed_text->placed_glyph_columns[placed_text->number_of_placed_glyphs] = width_of_current_line;
      placed_text->placed_glyph_rows[placed_text->number_of_placed_glyphs] = total_height;
      placed_text->placed_text_fonts[placed_text->number_of_placed_glyphs] = written_text.written_text_fonts[code_point_index];
      placed_text->placed_glyph_indices[placed_text->number_of_placed_glyphs] = written_text.written_glyph_indices[code_point_index];
      placed_text->placed_glyph_opacities[placed_text->number_of_placed_glyphs] = written_text.written_opacities[code_point_index];
      placed_text->placed_glyph_reds[placed_text->number_of_placed_glyphs] = written_text.written_reds[code_point_index];
      placed_text->placed_glyph_greens[placed_text->number_of_placed_glyphs] = written_text.written_greens[code_point_index];
      placed_text->placed_glyph_blues[placed_text->number_of_placed_glyphs] = written_text.written_blues[code_point_index];
      placed_text->number_of_placed_glyphs++;

      code_point_spacing_of_previous_character = text_font->code_point_spacing;
      width_of_current_line += text_font->glyph_widths[written_text.written_glyph_indices[code_point_index]];

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

  end_line(horizontal_alignment, placed_text, height_of_previous_line, height_of_current_line, line_spacing_of_previous_line, line_spacing_of_current_line, width_of_current_line, index_of_first_glyph_on_current_line, number_of_banked_lines);

  if (vertical_alignment == BELOW_TEXT_ANCHOR)
  {
    return placed_text->number_of_placed_glyphs;
  }

  total_height += (line_spacing_of_previous_line + height_of_previous_line) * number_of_banked_lines;

  if (vertical_alignment == CENTERED_ON_TEXT_ANCHOR)
  {
    total_height /= 2;
  }

  for (int glyph_index = 0; glyph_index < placed_text->number_of_placed_glyphs; glyph_index++)
  {
    placed_text->placed_glyph_rows[glyph_index] -= total_height;
  }

  return placed_text->number_of_placed_glyphs;
}
