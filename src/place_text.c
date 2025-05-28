#include "text_font.h"
#include "written_text.h"
#include "placed_text.h"
#include "place_text.h"

static void apply_horizontal_alignment_to_placed_text(
    const int horizontal_alignment,
    placed_text *const placed_text,
    const int width_of_current_line,
    const int height_of_current_line,
    const int index_of_first_glyph_on_current_line)
{
  for (int glyph_index = index_of_first_glyph_on_current_line; glyph_index < placed_text->number_of_placed_glyphs; glyph_index++)
  {
    placed_text->placed_glyph_rows[glyph_index] += height_of_current_line - placed_text->placed_text_fonts[glyph_index]->line_height;
  }

  if (horizontal_alignment == RIGHT_OF_TEXT_ANCHOR)
  {
    return;
  }

  const int amount_to_shift = horizontal_alignment == CENTERED_ON_TEXT_ANCHOR ? width_of_current_line / 2 : width_of_current_line;

  for (int glyph_index = index_of_first_glyph_on_current_line; glyph_index < placed_text->number_of_placed_glyphs; glyph_index++)
  {
    placed_text->placed_glyph_columns[glyph_index] -= amount_to_shift;
  }
}

int place_text(
    const written_text written_text,
    const int vertical_alignment,
    const int horizontal_alignment,
    placed_text *const placed_text)
{
  int total_height = 0;
  int height_of_current_line = 0;
  int line_spacing_of_current_line = 0;
  int width_of_current_line = 0;
  int code_point_spacing_of_previous_character = -1;
  int index_of_first_glyph_on_current_line = 0;

  for (int code_point_index = 0; code_point_index < written_text.number_of_written_code_points; code_point_index++)
  {
    const text_font *const text_font = written_text.written_text_fonts[code_point_index];

    if (written_text.written_glyph_indices[code_point_index] == -1)
    {
      apply_horizontal_alignment_to_placed_text(horizontal_alignment, placed_text, width_of_current_line, height_of_current_line, index_of_first_glyph_on_current_line);

      total_height += height_of_current_line > text_font->line_height ? height_of_current_line : text_font->line_height;
      total_height += line_spacing_of_current_line > text_font->line_spacing ? line_spacing_of_current_line : text_font->line_spacing;

      line_spacing_of_current_line = 0;
      height_of_current_line = 0;
      width_of_current_line = 0;
      code_point_spacing_of_previous_character = -1;
      index_of_first_glyph_on_current_line = placed_text->number_of_placed_glyphs;
    }
    else
    {
      if (placed_text->number_of_placed_glyphs == placed_text->number_of_placeable_glyphs)
      {
        return -1;
      }

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

  apply_horizontal_alignment_to_placed_text(horizontal_alignment, placed_text, width_of_current_line, height_of_current_line, index_of_first_glyph_on_current_line);

  if (vertical_alignment == BELOW_TEXT_ANCHOR)
  {
    return placed_text->number_of_placed_glyphs;
  }

  total_height += height_of_current_line;

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
