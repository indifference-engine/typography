#include <stdio.h>
#include <stdint.h>
#include "../../src/text_font.h"
#include "../../src/written_text.h"
#include "../../src/placed_text.h"
#include "../../src/start_text.h"
#include "../../src/place_text.h"
#include "../../src/write_text_code_point.h"
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

int main(const int argc, const char *const *const argv)
{
  (void)(argc);
  (void)(argv);

  const text_font *written_text_fonts[100];
  int written_glyph_indices[100];
  float written_opacities[100];
  float written_reds[100];
  float written_greens[100];
  float written_blues[100];
  written_text written = start_text(100, written_text_fonts, written_glyph_indices, written_opacities, written_reds, written_greens, written_blues);

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

  write_text_new_line(&written);
  write_text_new_line(&written);
  write_text_new_line(&written);
  write_text_code_point(10, &font_a, 0.4812841226f, 0.0778433944f, 0.1728721638f, 0.6958691477f, &written);
  write_text_new_line(&written);
  write_text_new_line(&written);

  const text_font *placed_text_fonts[100];
  int placed_glyph_indices[100];
  int placed_glyph_rows[100];
  int placed_glyph_columns[100];
  float placed_glyph_opacities[100];
  float placed_glyph_reds[100];
  float placed_glyph_greens[100];
  float placed_glyph_blues[100];
  placed_text placed = {
      .number_of_placeable_glyphs = 100,
      .placed_text_fonts = placed_text_fonts,
      .placed_glyph_indices = placed_glyph_indices,
      .placed_glyph_rows = placed_glyph_rows,
      .placed_glyph_columns = placed_glyph_columns,
      .placed_glyph_opacities = placed_glyph_opacities,
      .placed_glyph_reds = placed_glyph_reds,
      .placed_glyph_greens = placed_glyph_greens,
      .placed_glyph_blues = placed_glyph_blues,
  };

  place_text(written, BELOW_TEXT_ANCHOR, LEFT_OF_TEXT_ANCHOR, 1000, -2000, &placed);

  assert_int("placed glyphs", 0, placed.number_of_placed_glyphs);

  return exit_code;
}
