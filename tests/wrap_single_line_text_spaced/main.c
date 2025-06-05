#include <stdio.h>
#include <stdint.h>
#include "../../src/text_font.h"
#include "../../src/written_text.h"
#include "../../src/placed_text.h"
#include "../../src/start_text.h"
#include "../../src/place_text.h"
#include "../../src/write_text_code_point.h"
#include "../../src/write_text_new_line.h"
#include "../../src/wrap_text.h"

static int exit_code = 0;

static void assert_int(const char *const description, const int expected, const int actual)
{
  if (expected != actual)
  {
    fprintf(stderr, "Expected %d %s, actual %d.\n", expected, description, actual);
    exit_code = 1;
  }
}

static void checked_write_code_point(const text_font * const text_font, const uint32_t code_point, written_text * const written_text) {
  if (! write_text_code_point(code_point, text_font, 0.0f, 0.0f, 0.0f, 0.0f, written_text)) {
        fprintf(stderr, "Unexpectedly failed to write a code point.\n");
    exit_code = 1;
  }
}

static void check_placed(const placed_text placed_text, const int index, const text_font * const text_font, const uint32_t code_point, const int row, const int column)
{
  if (text_font != placed_text.placed_text_fonts[index]) {
    fprintf(stderr, "Incorrectly placed text font at index %d.\n", index);
    exit_code = 1;
  }

  const uint32_t actual_code_point = placed_text.placed_text_fonts[index]->glyph_code_points[placed_text.placed_glyph_indices[index]];

  if (code_point != actual_code_point) {
    fprintf(stderr, "Incorrectly placed code point at index %d (expected %d, actual %d).\n", index, code_point, actual_code_point);
    exit_code = 1;
  }

  if (row != placed_text.placed_glyph_rows[index]) {
    fprintf(stderr, "Incorrectly placed row at index %d (expected %d, actual %d).\n", index, row, placed_text.placed_glyph_rows[index]);
    exit_code = 1;
  }

  if (column != placed_text.placed_glyph_columns[index]) {
    fprintf(stderr, "Incorrectly placed column at index %d (expected %d, actual %d).\n", index, column, placed_text.placed_glyph_columns[index]);
    exit_code = 1;
  }
}

int main(const int argc, const char *const *const argv)
{
  (void)(argc);
  (void)(argv);

  const int glyph_widths_a[] = {6};
  const uint32_t glyph_code_points_a[] = {
      2294,
  };
  const int glyph_row_offsets_a[] = {0};

  const text_font text_font_a = {
      .code_point_spacing = 3,
      .line_spacing = 5,
      .line_height = 5,
      .glyph_widths = glyph_widths_a,
      .glyph_code_points = glyph_code_points_a,
      .glyph_row_offsets = glyph_row_offsets_a,
      .number_of_glyphs = 1};

  const int glyph_widths_b[] = {2, 8, 10, 12};
  const uint32_t glyph_code_points_b[] = {
      32, 7729145, 112313, 8235682
  };
  const int glyph_row_offsets_b[] = {0, 0, 0, 0};

  const text_font text_font_b = {
      .code_point_spacing = 3,
      .line_spacing = 5,
      .line_height = 5,
      .glyph_widths = glyph_widths_b,
      .glyph_code_points = glyph_code_points_b,
      .glyph_row_offsets = glyph_row_offsets_b,
      .number_of_glyphs = 4};

  const text_font *written_text_fonts[200];
  int written_glyph_indices[200];
  float written_opacities[200];
  float written_reds[200];
  float written_greens[200];
  float written_blues[200];
  written_text written_text = start_text(200, written_text_fonts, written_glyph_indices, written_opacities, written_reds, written_greens, written_blues);

  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_b, 32, &written_text);
  checked_write_code_point(&text_font_b, 7729145, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_b, 112313, &written_text);
  checked_write_code_point(&text_font_b, 8235682, &written_text);
  checked_write_code_point(&text_font_b, 112313, &written_text);
  checked_write_code_point(&text_font_b, 32, &written_text);
  checked_write_code_point(&text_font_b, 8235682, &written_text);
  checked_write_code_point(&text_font_b, 112313, &written_text);
  checked_write_code_point(&text_font_b, 32, &written_text);
  checked_write_code_point(&text_font_b, 32, &written_text);
  checked_write_code_point(&text_font_b, 7729145, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_b, 32, &written_text);
  checked_write_code_point(&text_font_b, 32, &written_text);
  checked_write_code_point(&text_font_b, 32, &written_text);

  wrap_text(129, &written_text);

  const text_font *placed_text_fonts[200];
  int placed_glyph_indices[200];
  int placed_glyph_rows[200];
  int placed_glyph_columns[200];
  float placed_glyph_opacities[200];
  float placed_glyph_reds[200];
  float placed_glyph_greens[200];
  float placed_glyph_blues[200];
  placed_text placed_text = {
      .number_of_placeable_glyphs = 200,
      .placed_text_fonts = placed_text_fonts,
      .placed_glyph_indices = placed_glyph_indices,
      .placed_glyph_rows = placed_glyph_rows,
      .placed_glyph_columns = placed_glyph_columns,
      .placed_glyph_opacities = placed_glyph_opacities,
      .placed_glyph_reds = placed_glyph_reds,
      .placed_glyph_greens = placed_glyph_greens,
      .placed_glyph_blues = placed_glyph_blues,
  };

  place_text(written_text, BELOW_TEXT_ANCHOR, RIGHT_OF_TEXT_ANCHOR, 0, 0, &placed_text);

  assert_int("number of placed glyphs", 16, placed_text.number_of_placed_glyphs);
  check_placed(placed_text, 0, &text_font_a, 2294, 0, 0);
  check_placed(placed_text, 1, &text_font_b, 32, 0, 9);
  check_placed(placed_text, 2, &text_font_b, 7729145, 0, 14);
  check_placed(placed_text, 3, &text_font_a, 2294, 0, 25);
  check_placed(placed_text, 4, &text_font_b, 112313, 0, 34);
  check_placed(placed_text, 5, &text_font_b, 8235682, 0, 47);
  check_placed(placed_text, 6, &text_font_b, 112313, 0, 62);
  check_placed(placed_text, 7, &text_font_b, 32, 0, 75);
  check_placed(placed_text, 8, &text_font_b, 8235682, 0, 80);
  check_placed(placed_text, 9, &text_font_b, 112313, 0, 95);
  check_placed(placed_text, 10, &text_font_b, 32, 0, 108);
  check_placed(placed_text, 11, &text_font_b, 7729145, 10, 0);
  check_placed(placed_text, 12, &text_font_a, 2294, 10, 11);
  check_placed(placed_text, 13, &text_font_b, 32, 10, 20);
  check_placed(placed_text, 14, &text_font_b, 32, 10, 25);
  check_placed(placed_text, 15, &text_font_b, 32, 10, 30);

  return exit_code;
}
