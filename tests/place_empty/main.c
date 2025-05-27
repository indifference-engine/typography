#include <stdio.h>
#include <stdint.h>
#include "../../src/text_font.h"
#include "../../src/written_text.h"
#include "../../src/placed_text.h"
#include "../../src/start_text.h"
#include "../../src/place_text.h"

int main(const int argc, const char *const *const argv)
{
  (void)(argc);
  (void)(argv);

  const text_font *written_text_fonts[7];
  int written_glyph_indices[7];
  float written_opacities[7];
  float written_reds[7];
  float written_greens[7];
  float written_blues[7];
  written_text written = start_text(7, written_text_fonts, written_glyph_indices, written_opacities, written_reds, written_greens, written_blues);

  const text_font *placed_text_fonts[6];
  int placed_glyph_indices[6];
  int placed_glyph_rows[6];
  int placed_glyph_columns[6];
  float placed_glyph_opacities[6];
  float placed_glyph_reds[6];
  float placed_glyph_greens[6];
  float placed_glyph_blues[6];
  placed_text placed = {
      .number_of_placeable_glyphs = 6,
      .placed_text_fonts = placed_text_fonts,
      .placed_glyph_indices = placed_glyph_indices,
      .placed_glyph_rows = placed_glyph_rows,
      .placed_glyph_columns = placed_glyph_columns,
      .placed_glyph_opacities = placed_glyph_opacities,
      .placed_glyph_reds = placed_glyph_reds,
      .placed_glyph_greens = placed_glyph_greens,
      .placed_glyph_blues = placed_glyph_blues,
  };

  const int number_of_placed_glyphs = place_text(written, BELOW_TEXT_ANCHOR, RIGHT_OF_TEXT_ANCHOR, &placed);

  if (number_of_placed_glyphs != 0)
  {
    fprintf(stderr, "Expected 0 placed glyphs, actual %d.\n", number_of_placed_glyphs);
    return 1;
  }

  return 0;
}
