#include <stdbool.h>
#include <stdint.h>
#include "text_state.h"
#include "write_text_code_point.h"

bool write_text_code_point(
    const uint32_t code_point,
    const text_font *const text_font,
    const float opacity,
    const float red,
    const float green,
    const float blue,
    text_state *const text_state)
{
  const int number_of_written_code_points = text_state->number_of_written_code_points;

  if (number_of_written_code_points == text_state->number_of_writable_code_points)
  {
    return false;
  }

  text_state->written_glyph_indices[number_of_written_code_points] = code_point;
  text_state->written_text_fonts[number_of_written_code_points] = text_font;
  text_state->written_opacities[number_of_written_code_points] = opacity;
  text_state->written_reds[number_of_written_code_points] = red;
  text_state->written_greens[number_of_written_code_points] = green;
  text_state->written_blues[number_of_written_code_points] = blue;
  text_state->written_glyph_indices[number_of_written_code_points] = code_point;

  text_state->number_of_written_code_points = number_of_written_code_points + 1;

  return true;
}
