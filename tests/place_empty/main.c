#include <stdio.h>
#include <stdint.h>
#include "../../src/text_font.h"
#include "../../src/text_state.h"
#include "../../src/start_text.h"
#include "../../src/place_text.h"

int main(const int argc, const char *const *const argv)
{
  (void)(argc);
  (void)(argv);

  int written_glyph_indices[7];
  text_state state = start_text(7, written_glyph_indices);

  const int glyph_widths[] = {23, 18, 19, 25};
  const uint32_t glyph_code_points[] = {505255796, 204668171, 358868195, 402862483};

  const text_font font = {
      .code_point_spacing = 5,
      .line_spacing = 3,
      .line_height = 12,
      .glyph_widths = glyph_widths,
      .glyph_code_points = glyph_code_points,
      .number_of_glyphs = 4};

  int placed_glyph_indices[6];
  int placed_glyph_rows[6];
  int placed_glyph_columns[6];
  const int number_of_placed_glyphs = place_text(
      font,
      state,
      6,
      placed_glyph_indices,
      placed_glyph_rows,
      placed_glyph_columns);

  if (number_of_placed_glyphs != 0)
  {
    fprintf(stderr, "Expected 0 placed glyphs, actual %d.\n", number_of_placed_glyphs);
    return 1;
  }

  return 0;
}
