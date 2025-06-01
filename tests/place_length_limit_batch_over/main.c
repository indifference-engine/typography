#include <stdio.h>
#include <stdint.h>
#include "../../src/text_font.h"
#include "../../src/written_text.h"
#include "../../src/placed_text.h"
#include "../../src/start_text.h"
#include "../../src/place_text.h"
#include "../../src/write_text_code_points.h"
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

  const text_font *written_text_fonts[7];
  int written_glyph_indices[7];
  float written_opacities[7];
  float written_reds[7];
  float written_greens[7];
  float written_blues[7];
  written_text written = start_text(7, written_text_fonts, written_glyph_indices, written_opacities, written_reds, written_greens, written_blues);

  const int glyph_widths_a[] = {23, 18, 19, 25};
  const uint32_t glyph_code_points_a[] = {505255796, 204668171, 358868195, 402862483};
  const int glyph_row_offsets_a[] = {5, -7, 8, 2};

  const text_font font_a = {
      .code_point_spacing = 5,
      .line_spacing = 3,
      .line_height = 12,
      .glyph_widths = glyph_widths_a,
      .glyph_code_points = glyph_code_points_a,
      .glyph_row_offsets = glyph_row_offsets_a,
      .number_of_glyphs = 4};

  uint32_t code_points[] = {204668171, 505255796, 204668171, 10, 358868195, 505255796, 204668171, 358868195, 402862483, 0};

  if (write_text_code_points(code_points, &font_a, 0.1564262168f, 0.0437286089f, 0.2452098142f, 0.4578030974f, &written))
  {
    fprintf(stderr, "Unexpectedly succeeded in writing code points.\n");
    exit_code = 1;
  }

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

  place_text(written, BELOW_TEXT_ANCHOR, RIGHT_OF_TEXT_ANCHOR, 1000, -2000, &placed);

  assert_int("placed glyphs", 6, placed.number_of_placed_glyphs);

  assert_pointer("placed text font a", &font_a, placed_text_fonts[0]);
  assert_pointer("placed text font b", &font_a, placed_text_fonts[1]);
  assert_pointer("placed text font c", &font_a, placed_text_fonts[2]);
  assert_pointer("placed text font d", &font_a, placed_text_fonts[3]);
  assert_pointer("placed text font e", &font_a, placed_text_fonts[4]);
  assert_pointer("placed text font f", &font_a, placed_text_fonts[5]);

  assert_int("placed glyph index a", 1, placed_glyph_indices[0]);
  assert_int("placed glyph index b", 0, placed_glyph_indices[1]);
  assert_int("placed glyph index c", 1, placed_glyph_indices[2]);
  assert_int("placed glyph index d", 2, placed_glyph_indices[3]);
  assert_int("placed glyph index e", 0, placed_glyph_indices[4]);
  assert_int("placed glyph index f", 1, placed_glyph_indices[5]);

  assert_int("placed glyph row a", 993, placed_glyph_rows[0]);
  assert_int("placed glyph row b", 1005, placed_glyph_rows[1]);
  assert_int("placed glyph row c", 993, placed_glyph_rows[2]);
  assert_int("placed glyph row d", 1023, placed_glyph_rows[3]);
  assert_int("placed glyph row e", 1020, placed_glyph_rows[4]);
  assert_int("placed glyph row f", 1008, placed_glyph_rows[5]);

  assert_int("placed glyph column a", -2000, placed_glyph_columns[0]);
  assert_int("placed glyph column b", -1977, placed_glyph_columns[1]);
  assert_int("placed glyph column c", -1949, placed_glyph_columns[2]);
  assert_int("placed glyph column d", -2000, placed_glyph_columns[3]);
  assert_int("placed glyph column e", -1976, placed_glyph_columns[4]);
  assert_int("placed glyph column f", -1948, placed_glyph_columns[5]);

  assert_float("placed glyph opacity a", 0.1564262168f, placed_glyph_opacities[0]);
  assert_float("placed glyph opacity b", 0.1564262168f, placed_glyph_opacities[1]);
  assert_float("placed glyph opacity c", 0.1564262168f, placed_glyph_opacities[2]);
  assert_float("placed glyph opacity d", 0.1564262168f, placed_glyph_opacities[3]);
  assert_float("placed glyph opacity e", 0.1564262168f, placed_glyph_opacities[4]);
  assert_float("placed glyph opacity f", 0.1564262168f, placed_glyph_opacities[5]);

  assert_float("placed glyph red a", 0.0437286089f, placed_glyph_reds[0]);
  assert_float("placed glyph red b", 0.0437286089f, placed_glyph_reds[1]);
  assert_float("placed glyph red c", 0.0437286089f, placed_glyph_reds[2]);
  assert_float("placed glyph red d", 0.0437286089f, placed_glyph_reds[3]);
  assert_float("placed glyph red e", 0.0437286089f, placed_glyph_reds[4]);
  assert_float("placed glyph red f", 0.0437286089f, placed_glyph_reds[5]);

  assert_float("placed glyph green a", 0.2452098142f, placed_glyph_greens[0]);
  assert_float("placed glyph green b", 0.2452098142f, placed_glyph_greens[1]);
  assert_float("placed glyph green c", 0.2452098142f, placed_glyph_greens[2]);
  assert_float("placed glyph green d", 0.2452098142f, placed_glyph_greens[3]);
  assert_float("placed glyph green e", 0.2452098142f, placed_glyph_greens[4]);
  assert_float("placed glyph green f", 0.2452098142f, placed_glyph_greens[5]);

  assert_float("placed glyph blue a", 0.4578030974f, placed_glyph_blues[0]);
  assert_float("placed glyph blue b", 0.4578030974f, placed_glyph_blues[1]);
  assert_float("placed glyph blue c", 0.4578030974f, placed_glyph_blues[2]);
  assert_float("placed glyph blue d", 0.4578030974f, placed_glyph_blues[3]);
  assert_float("placed glyph blue e", 0.4578030974f, placed_glyph_blues[4]);
  assert_float("placed glyph blue f", 0.4578030974f, placed_glyph_blues[5]);

  return exit_code;
}
