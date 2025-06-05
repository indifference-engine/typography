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

static void checked_write_new_line(written_text * const written_text) {
  if (! write_text_new_line(written_text)) {
    fprintf(stderr, "Unexpectedly failed to write a new line.\n");
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

  const int glyph_widths_c[] = {12};
  const uint32_t glyph_code_points_c[] = {
      12124124,
  };
  const int glyph_row_offsets_c[] = {0};

  const text_font text_font_c = {
      .code_point_spacing = 10,
      .line_spacing = 5,
      .line_height = 5,
      .glyph_widths = glyph_widths_c,
      .glyph_code_points = glyph_code_points_c,
      .glyph_row_offsets = glyph_row_offsets_c,
      .number_of_glyphs = 1};

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
  checked_write_new_line(&written_text);
  checked_write_code_point(&text_font_b, 7729145, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_b, 32, &written_text);
  checked_write_code_point(&text_font_b, 32, &written_text);
  checked_write_code_point(&text_font_b, 32, &written_text);
  checked_write_new_line(&written_text);
  checked_write_code_point(&text_font_b, 8235682, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_b, 32, &written_text);
  checked_write_code_point(&text_font_b, 8235682, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_b, 32, &written_text);
  checked_write_code_point(&text_font_b, 32, &written_text);
  checked_write_code_point(&text_font_b, 32, &written_text);
  checked_write_code_point(&text_font_b, 32, &written_text);
  checked_write_code_point(&text_font_b, 7729145, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_b, 112313, &written_text);
  checked_write_code_point(&text_font_b, 8235682, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_new_line(&written_text);
  checked_write_code_point(&text_font_b, 8235682, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_new_line(&written_text);
  checked_write_code_point(&text_font_b, 8235682, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_new_line(&written_text);
  checked_write_code_point(&text_font_c, 12124124, &written_text);
  checked_write_code_point(&text_font_c, 12124124, &written_text);
  checked_write_code_point(&text_font_c, 12124124, &written_text);
  checked_write_code_point(&text_font_c, 12124124, &written_text);
  checked_write_code_point(&text_font_c, 12124124, &written_text);
  checked_write_code_point(&text_font_c, 12124124, &written_text);
  checked_write_code_point(&text_font_c, 12124124, &written_text);
  checked_write_code_point(&text_font_c, 12124124, &written_text);
  checked_write_code_point(&text_font_b, 32, &written_text);
  checked_write_code_point(&text_font_c, 12124124, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_c, 12124124, &written_text);
  checked_write_code_point(&text_font_c, 12124124, &written_text);
  checked_write_code_point(&text_font_b, 112313, &written_text);
  checked_write_code_point(&text_font_b, 112313, &written_text);
  checked_write_code_point(&text_font_b, 32, &written_text);
  checked_write_code_point(&text_font_b, 32, &written_text);
  checked_write_code_point(&text_font_c, 12124124, &written_text);
  checked_write_code_point(&text_font_c, 12124124, &written_text);
  checked_write_code_point(&text_font_c, 12124124, &written_text);
  checked_write_code_point(&text_font_c, 12124124, &written_text);
  checked_write_code_point(&text_font_c, 12124124, &written_text);
  checked_write_code_point(&text_font_c, 12124124, &written_text);
  checked_write_code_point(&text_font_c, 12124124, &written_text);
  checked_write_code_point(&text_font_c, 12124124, &written_text);
  checked_write_new_line(&written_text);
  checked_write_code_point(&text_font_c, 12124124, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_a, 2294, &written_text);
  checked_write_code_point(&text_font_c, 12124124, &written_text);
  checked_write_code_point(&text_font_c, 12124124, &written_text);
  checked_write_code_point(&text_font_b, 112313, &written_text);
  checked_write_code_point(&text_font_b, 112313, &written_text);
  checked_write_code_point(&text_font_b, 32, &written_text);
  checked_write_new_line(&written_text);
  checked_write_code_point(&text_font_c, 12124124, &written_text);

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

  assert_int("number of placed glyphs", 119, placed_text.number_of_placed_glyphs);
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
  check_placed(placed_text, 16, &text_font_b, 8235682, 20, 0);
  check_placed(placed_text, 17, &text_font_a, 2294, 20, 15);
  check_placed(placed_text, 18, &text_font_a, 2294, 20, 24);
  check_placed(placed_text, 19, &text_font_a, 2294, 20, 33);
  check_placed(placed_text, 20, &text_font_a, 2294, 20, 42);
  check_placed(placed_text, 21, &text_font_a, 2294, 20, 51);
  check_placed(placed_text, 22, &text_font_a, 2294, 20, 60);
  check_placed(placed_text, 23, &text_font_a, 2294, 20, 69);
  check_placed(placed_text, 24, &text_font_a, 2294, 20, 78);
  check_placed(placed_text, 25, &text_font_a, 2294, 20, 87);
  check_placed(placed_text, 26, &text_font_a, 2294, 20, 96);
  check_placed(placed_text, 27, &text_font_a, 2294, 20, 105);
  check_placed(placed_text, 28, &text_font_a, 2294, 20, 114);
  check_placed(placed_text, 29, &text_font_a, 2294, 20, 123);
  check_placed(placed_text, 30, &text_font_b, 8235682, 30, 0);
  check_placed(placed_text, 31, &text_font_a, 2294, 30, 15);
  check_placed(placed_text, 32, &text_font_a, 2294, 30, 24);
  check_placed(placed_text, 33, &text_font_a, 2294, 30, 33);
  check_placed(placed_text, 34, &text_font_a, 2294, 30, 42);
  check_placed(placed_text, 35, &text_font_a, 2294, 30, 51);
  check_placed(placed_text, 36, &text_font_a, 2294, 30, 60);
  check_placed(placed_text, 37, &text_font_a, 2294, 30, 69);
  check_placed(placed_text, 38, &text_font_a, 2294, 30, 78);
  check_placed(placed_text, 39, &text_font_a, 2294, 30, 87);
  check_placed(placed_text, 40, &text_font_a, 2294, 30, 96);
  check_placed(placed_text, 41, &text_font_a, 2294, 30, 105);
  check_placed(placed_text, 42, &text_font_a, 2294, 30, 114);
  check_placed(placed_text, 43, &text_font_a, 2294, 30, 123);
  check_placed(placed_text, 44, &text_font_a, 2294, 30, 132);
  check_placed(placed_text, 45, &text_font_a, 2294, 30, 141);
  check_placed(placed_text, 46, &text_font_b, 32, 40, 0);
  check_placed(placed_text, 47, &text_font_b, 32, 40, 5);
  check_placed(placed_text, 48, &text_font_b, 32, 40, 10);
  check_placed(placed_text, 49, &text_font_b, 7729145, 40, 15);
  check_placed(placed_text, 50, &text_font_a, 2294, 40, 26);
  check_placed(placed_text, 51, &text_font_b, 112313, 40, 35);
  check_placed(placed_text, 52, &text_font_b, 8235682, 40, 48);
  check_placed(placed_text, 53, &text_font_a, 2294, 40, 63);
  check_placed(placed_text, 54, &text_font_b, 8235682, 50, 0);
  check_placed(placed_text, 55, &text_font_a, 2294, 50, 15);
  check_placed(placed_text, 56, &text_font_a, 2294, 50, 24);
  check_placed(placed_text, 57, &text_font_a, 2294, 50, 33);
  check_placed(placed_text, 58, &text_font_a, 2294, 50, 42);
  check_placed(placed_text, 59, &text_font_a, 2294, 50, 51);
  check_placed(placed_text, 60, &text_font_a, 2294, 50, 60);
  check_placed(placed_text, 61, &text_font_a, 2294, 50, 69);
  check_placed(placed_text, 62, &text_font_a, 2294, 50, 78);
  check_placed(placed_text, 63, &text_font_a, 2294, 50, 87);
  check_placed(placed_text, 64, &text_font_a, 2294, 50, 96);
  check_placed(placed_text, 65, &text_font_a, 2294, 50, 105);
  check_placed(placed_text, 66, &text_font_a, 2294, 50, 114);
  check_placed(placed_text, 67, &text_font_a, 2294, 50, 123);
  check_placed(placed_text, 68, &text_font_b, 8235682, 60, 0);
  check_placed(placed_text, 69, &text_font_a, 2294, 60, 15);
  check_placed(placed_text, 70, &text_font_a, 2294, 60, 24);
  check_placed(placed_text, 71, &text_font_a, 2294, 60, 33);
  check_placed(placed_text, 72, &text_font_a, 2294, 60, 42);
  check_placed(placed_text, 73, &text_font_a, 2294, 60, 51);
  check_placed(placed_text, 74, &text_font_a, 2294, 60, 60);
  check_placed(placed_text, 75, &text_font_a, 2294, 60, 69);
  check_placed(placed_text, 76, &text_font_a, 2294, 60, 78);
  check_placed(placed_text, 77, &text_font_a, 2294, 60, 87);
  check_placed(placed_text, 78, &text_font_a, 2294, 60, 96);
  check_placed(placed_text, 79, &text_font_a, 2294, 60, 105);
  check_placed(placed_text, 80, &text_font_a, 2294, 60, 114);
  check_placed(placed_text, 81, &text_font_a, 2294, 60, 123);
  check_placed(placed_text, 82, &text_font_a, 2294, 60, 132);
  check_placed(placed_text, 83, &text_font_a, 2294, 60, 141);
  check_placed(placed_text, 84, &text_font_c, 12124124, 70, 0);
  check_placed(placed_text, 85, &text_font_c, 12124124, 70, 22);
  check_placed(placed_text, 86, &text_font_c, 12124124, 70, 44);
  check_placed(placed_text, 87, &text_font_c, 12124124, 70, 66);
  check_placed(placed_text, 88, &text_font_c, 12124124, 70, 88);
  check_placed(placed_text, 89, &text_font_c, 12124124, 70, 110);
  check_placed(placed_text, 90, &text_font_c, 12124124, 70, 132);
  check_placed(placed_text, 91, &text_font_c, 12124124, 70, 154);
  check_placed(placed_text, 92, &text_font_c, 12124124, 80, 0);
  check_placed(placed_text, 93, &text_font_a, 2294, 80, 22);
  check_placed(placed_text, 94, &text_font_a, 2294, 80, 31);
  check_placed(placed_text, 95, &text_font_a, 2294, 80, 40);
  check_placed(placed_text, 96, &text_font_c, 12124124, 80, 56);
  check_placed(placed_text, 97, &text_font_c, 12124124, 80, 78);
  check_placed(placed_text, 98, &text_font_b, 112313, 80, 100);
  check_placed(placed_text, 99, &text_font_b, 112313, 80, 113);
  check_placed(placed_text, 100, &text_font_b, 32, 80, 126);
  check_placed(placed_text, 101, &text_font_c, 12124124, 90, 0);
  check_placed(placed_text, 102, &text_font_c, 12124124, 90, 22);
  check_placed(placed_text, 103, &text_font_c, 12124124, 90, 44);
  check_placed(placed_text, 104, &text_font_c, 12124124, 90, 66);
  check_placed(placed_text, 105, &text_font_c, 12124124, 90, 88);
  check_placed(placed_text, 106, &text_font_c, 12124124, 90, 110);
  check_placed(placed_text, 107, &text_font_c, 12124124, 90, 132);
  check_placed(placed_text, 108, &text_font_c, 12124124, 90, 154);
  check_placed(placed_text, 109, &text_font_c, 12124124, 100, 0);
  check_placed(placed_text, 110, &text_font_a, 2294, 100, 22);
  check_placed(placed_text, 111, &text_font_a, 2294, 100, 31);
  check_placed(placed_text, 112, &text_font_a, 2294, 100, 40);
  check_placed(placed_text, 113, &text_font_c, 12124124, 100, 56);
  check_placed(placed_text, 114, &text_font_c, 12124124, 100, 78);
  check_placed(placed_text, 115, &text_font_b, 112313, 100, 100);
  check_placed(placed_text, 116, &text_font_b, 112313, 100, 113);
  check_placed(placed_text, 117, &text_font_b, 32, 100, 126);
  check_placed(placed_text, 118, &text_font_c, 12124124, 110, 0);

  return exit_code;
}
