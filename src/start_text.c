#include "text_state.h"
#include "start_text.h"

text_state start_text(
    const int number_of_writable_code_points,
    int *const written_glyph_indices)
{
  const text_state output = {
      .number_of_written_code_points = 0,
      .number_of_writable_code_points = number_of_writable_code_points,
      .written_glyph_indices = written_glyph_indices};

  return output;
}
