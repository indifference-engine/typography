#include "text_font.h"
#include "text_state.h"
#include "place_text.h"

int place_text(
    const text_font text_font,
    const text_state text_state,
    const int vertical_alignment,
    const int horizontal_alignment,
    const int number_of_placeable_glyphs,
    int *const placed_glyph_indices,
    int *const placed_glyph_rows,
    int *const placed_glyph_columns)
{
  (void)(text_font);
  (void)(text_state);
  (void)(vertical_alignment);
  (void)(horizontal_alignment);
  (void)(number_of_placeable_glyphs);
  (void)(placed_glyph_indices);
  (void)(placed_glyph_rows);
  (void)(placed_glyph_columns);
  return 0;
}
