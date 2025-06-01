#include <stdio.h>
#include <stdint.h>
#include "../../src/text_font.h"
#include "../../src/written_text.h"
#include "../../src/placed_text.h"
#include "../../src/start_text.h"
#include "../../src/place_text.h"
#include "../../src/write_text_int.h"
#include "../../src/write_text_new_line.h"

static int exit_code = 0;

static void assert_int(const char *const description, const int expected, const int actual)
{
  if (expected != actual)
  {
    fprintf(stderr, "Expected %d %s, actual %d.\n", expected, description, actual);
    exit_code = 1;
  }
}

static void assert_float(const char *const description, const float expected, const float actual)
{
  if (expected != actual)
  {
    fprintf(stderr, "Expected %f %s, actual %f.\n", expected, description, actual);
    exit_code = 1;
  }
}

static void assert_pointer(const char *const description, const void *const expected, const void *const actual)
{
  if (expected != actual)
  {
    fprintf(stderr, "Expected %p %s, actual %p.\n", expected, description, actual);
    exit_code = 1;
  }
}

int main(const int argc, const char *const *const argv)
{
  (void)(argc);
  (void)(argv);

  const text_font *written_text_fonts[1];
  int written_glyph_indices[1];
  float written_opacities[1];
  float written_reds[1];
  float written_greens[1];
  float written_blues[1];
  written_text written = start_text(1, written_text_fonts, written_glyph_indices, written_opacities, written_reds, written_greens, written_blues);

  const int glyph_widths_a[] = {23, 18, 19, 25, 12, 45, 8, 9, 2, 6, 8, 11, 9, 3, 5};
  const uint32_t glyph_code_points_a[] = {
      505255796,
      49,
      53,
      54,
      55,
      50,
      56,
      204668171,
      52,
      51,
      45,
      358868195,
      48,
      402862483,
      57,
  };
  const int glyph_row_offsets_a[] = {5, -7, 8, 2, -3, 8, 10, -5, 7, 9, 3, 2, 11, -4, 5};

  const text_font font_a = {
      .code_point_spacing = 5,
      .line_spacing = 3,
      .line_height = 12,
      .glyph_widths = glyph_widths_a,
      .glyph_code_points = glyph_code_points_a,
      .glyph_row_offsets = glyph_row_offsets_a,
      .number_of_glyphs = 15};

  if (!write_text_int(0, &font_a, 0.1564262168f, 0.0437286089f, 0.2452098142f, 0.4578030974f, &written))
  {
    fprintf(stderr, "Unexpectedly failed to write int.\n");
    exit_code = 1;
  }

  const text_font *placed_text_fonts[1];
  int placed_glyph_indices[1];
  int placed_glyph_rows[1];
  int placed_glyph_columns[1];
  float placed_glyph_opacities[1];
  float placed_glyph_reds[1];
  float placed_glyph_greens[1];
  float placed_glyph_blues[1];
  placed_text placed = {
      .number_of_placeable_glyphs = 1,
      .placed_text_fonts = placed_text_fonts,
      .placed_glyph_indices = placed_glyph_indices,
      .placed_glyph_rows = placed_glyph_rows,
      .placed_glyph_columns = placed_glyph_columns,
      .placed_glyph_opacities = placed_glyph_opacities,
      .placed_glyph_reds = placed_glyph_reds,
      .placed_glyph_greens = placed_glyph_greens,
      .placed_glyph_blues = placed_glyph_blues,
  };

  place_text(written, BELOW_TEXT_ANCHOR, RIGHT_OF_TEXT_ANCHOR, 1000, -2000, &placed);

  assert_int("placed glyphs", 1, placed.number_of_placed_glyphs);
  assert_pointer("placed text font a", &font_a, placed_text_fonts[0]);
  assert_int("placed glyph index a", 12, placed_glyph_indices[0]);
  assert_int("placed glyph row a", 1011, placed_glyph_rows[0]);
  assert_int("placed glyph column a", -2000, placed_glyph_columns[0]);
  assert_float("placed glyph opacity a", 0.1564262168f, placed_glyph_opacities[0]);
  assert_float("placed glyph red a", 0.0437286089f, placed_glyph_reds[0]);
  assert_float("placed glyph green a", 0.2452098142f, placed_glyph_greens[0]);
  assert_float("placed glyph blue a", 0.4578030974f, placed_glyph_blues[0]);

  return exit_code;
}
