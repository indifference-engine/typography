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

  const int glyph_widths_b[] = {50, 49, 37};
  const uint32_t glyph_code_points_b[] = {204668171, 505255796, 37498374};
  const int glyph_row_offsets_b[] = {3, 9, -2};

  const text_font font_b = {
      .code_point_spacing = 41,
      .line_spacing = 25,
      .line_height = 17,
      .glyph_widths = glyph_widths_b,
      .glyph_code_points = glyph_code_points_b,
      .glyph_row_offsets = glyph_row_offsets_b,
      .number_of_glyphs = 3};

  write_text_new_line(&written);
  write_text_new_line(&written);
  write_text_new_line(&written);
  write_text_code_point(204668171, &font_a, 0.1564262168f, 0.0437286089f, 0.2452098142f, 0.4578030974f, &written);
  write_text_code_point(505255796, &font_b, 0.3664873978f, 0.8843461135f, 0.0204608919f, 0.8177569126f, &written);
  write_text_code_point(204668171, &font_b, 0.5377511140f, 0.6091213575f, 0.3598658273f, 0.4994471018f, &written);
  write_text_new_line(&written);
  write_text_new_line(&written);
  write_text_code_point(37498374, &font_b, 0.1292127857f, 0.3058116156f, 0.5600688226f, 0.6124764171f, &written);
  write_text_code_point(505255796, &font_a, 0.0826451742f, 0.7329012169f, 0.3891597672f, 0.3621127009f, &written);
  write_text_code_point(204668171, &font_a, 0.6479530738f, 0.2324556519f, 0.6618752571f, 0.2592586932f, &written);
  write_text_new_line(&written);
  write_text_code_point(505255796, &font_a, 0.3675602343f, 0.7996827598f, 0.3451825441f, 0.9147162815f, &written);
  write_text_code_point(204668171, &font_a, 0.2773437981f, 0.2373427736f, 0.4793238467f, 0.0459671612f, &written);
  write_text_new_line(&written);
  write_text_code_point(10, &font_b, 0.4812841226f, 0.0778433944f, 0.1728721638f, 0.6958691477f, &written);
  write_text_new_line(&written);
  write_text_new_line(&written);
  write_text_code_point(505255796, &font_a, 0.2505802000f, 0.0866405098f, 0.6444550980f, 0.0194627529f, &written);
  write_text_new_line(&written);
  write_text_code_point(37498374, &font_b, 0.0485073004f, 0.9620940975f, 0.3221459797f, 0.2956948430f, &written);
  write_text_code_point(505255796, &font_a, 0.9424165809f, 0.9834774777f, 0.6251162386f, 0.3117195449f, &written);
  write_text_new_line(&written);
  write_text_new_line(&written);
  write_text_new_line(&written);
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

  place_text(written, BELOW_TEXT_ANCHOR, CENTERED_ON_TEXT_ANCHOR, &placed);

  assert_int("placed glyphs", 11, placed.number_of_placed_glyphs);

  assert_pointer("placed text font a", &font_a, placed_text_fonts[0]);
  assert_pointer("placed text font b", &font_b, placed_text_fonts[1]);
  assert_pointer("placed text font c", &font_b, placed_text_fonts[2]);
  assert_pointer("placed text font d", &font_b, placed_text_fonts[3]);
  assert_pointer("placed text font e", &font_a, placed_text_fonts[4]);
  assert_pointer("placed text font f", &font_a, placed_text_fonts[5]);
  assert_pointer("placed text font g", &font_a, placed_text_fonts[6]);
  assert_pointer("placed text font h", &font_a, placed_text_fonts[7]);
  assert_pointer("placed text font i", &font_a, placed_text_fonts[8]);
  assert_pointer("placed text font j", &font_b, placed_text_fonts[9]);
  assert_pointer("placed text font k", &font_a, placed_text_fonts[10]);

  assert_int("placed glyph index a", 1, placed_glyph_indices[0]);
  assert_int("placed glyph index b", 1, placed_glyph_indices[1]);
  assert_int("placed glyph index c", 0, placed_glyph_indices[2]);
  assert_int("placed glyph index d", 2, placed_glyph_indices[3]);
  assert_int("placed glyph index e", 0, placed_glyph_indices[4]);
  assert_int("placed glyph index f", 1, placed_glyph_indices[5]);
  assert_int("placed glyph index g", 0, placed_glyph_indices[6]);
  assert_int("placed glyph index h", 1, placed_glyph_indices[7]);
  assert_int("placed glyph index i", 0, placed_glyph_indices[8]);
  assert_int("placed glyph index j", 2, placed_glyph_indices[9]);
  assert_int("placed glyph index k", 0, placed_glyph_indices[10]);

  assert_int("placed glyph row a", 124, placed_glyph_rows[0]);
  assert_int("placed glyph row b", 135, placed_glyph_rows[1]);
  assert_int("placed glyph row c", 129, placed_glyph_rows[2]);
  assert_int("placed glyph row d", 208, placed_glyph_rows[3]);
  assert_int("placed glyph row e", 220, placed_glyph_rows[4]);
  assert_int("placed glyph row f", 208, placed_glyph_rows[5]);
  assert_int("placed glyph row g", 257, placed_glyph_rows[6]);
  assert_int("placed glyph row h", 245, placed_glyph_rows[7]);
  assert_int("placed glyph row i", 317, placed_glyph_rows[8]);
  assert_int("placed glyph row j", 347, placed_glyph_rows[9]);
  assert_int("placed glyph row k", 359, placed_glyph_rows[10]);

  assert_int("placed glyph column a", -99, placed_glyph_columns[0]);
  assert_int("placed glyph column b", -40, placed_glyph_columns[1]);
  assert_int("placed glyph column c", 50, placed_glyph_columns[2]);
  assert_int("placed glyph column d", -62, placed_glyph_columns[3]);
  assert_int("placed glyph column e", 16, placed_glyph_columns[4]);
  assert_int("placed glyph column f", 44, placed_glyph_columns[5]);
  assert_int("placed glyph column g", -23, placed_glyph_columns[6]);
  assert_int("placed glyph column h", 5, placed_glyph_columns[7]);
  assert_int("placed glyph column i", -11, placed_glyph_columns[8]);
  assert_int("placed glyph column j", -50, placed_glyph_columns[9]);
  assert_int("placed glyph column k", 28, placed_glyph_columns[10]);

  assert_float("placed glyph opacity a", 0.1564262168f, placed_glyph_opacities[0]);
  assert_float("placed glyph opacity b", 0.3664873978f, placed_glyph_opacities[1]);
  assert_float("placed glyph opacity c", 0.5377511140f, placed_glyph_opacities[2]);
  assert_float("placed glyph opacity d", 0.1292127857f, placed_glyph_opacities[3]);
  assert_float("placed glyph opacity e", 0.0826451742f, placed_glyph_opacities[4]);
  assert_float("placed glyph opacity f", 0.6479530738f, placed_glyph_opacities[5]);
  assert_float("placed glyph opacity g", 0.3675602343f, placed_glyph_opacities[6]);
  assert_float("placed glyph opacity h", 0.2773437981f, placed_glyph_opacities[7]);
  assert_float("placed glyph opacity i", 0.2505802000f, placed_glyph_opacities[8]);
  assert_float("placed glyph opacity j", 0.0485073004f, placed_glyph_opacities[9]);
  assert_float("placed glyph opacity k", 0.9424165809f, placed_glyph_opacities[10]);

  assert_float("placed glyph red a", 0.0437286089f, placed_glyph_reds[0]);
  assert_float("placed glyph red b", 0.8843461135f, placed_glyph_reds[1]);
  assert_float("placed glyph red c", 0.6091213575f, placed_glyph_reds[2]);
  assert_float("placed glyph red d", 0.3058116156f, placed_glyph_reds[3]);
  assert_float("placed glyph red e", 0.7329012169f, placed_glyph_reds[4]);
  assert_float("placed glyph red f", 0.2324556519f, placed_glyph_reds[5]);
  assert_float("placed glyph red g", 0.7996827598f, placed_glyph_reds[6]);
  assert_float("placed glyph red h", 0.2373427736f, placed_glyph_reds[7]);
  assert_float("placed glyph red i", 0.0866405098f, placed_glyph_reds[8]);
  assert_float("placed glyph red j", 0.9620940975f, placed_glyph_reds[9]);
  assert_float("placed glyph red k", 0.9834774777f, placed_glyph_reds[10]);

  assert_float("placed glyph green a", 0.2452098142f, placed_glyph_greens[0]);
  assert_float("placed glyph green b", 0.0204608919f, placed_glyph_greens[1]);
  assert_float("placed glyph green c", 0.3598658273f, placed_glyph_greens[2]);
  assert_float("placed glyph green d", 0.5600688226f, placed_glyph_greens[3]);
  assert_float("placed glyph green e", 0.3891597672f, placed_glyph_greens[4]);
  assert_float("placed glyph green f", 0.6618752571f, placed_glyph_greens[5]);
  assert_float("placed glyph green g", 0.3451825441f, placed_glyph_greens[6]);
  assert_float("placed glyph green h", 0.4793238467f, placed_glyph_greens[7]);
  assert_float("placed glyph green i", 0.6444550980f, placed_glyph_greens[8]);
  assert_float("placed glyph green j", 0.3221459797f, placed_glyph_greens[9]);
  assert_float("placed glyph green k", 0.6251162386f, placed_glyph_greens[10]);

  assert_float("placed glyph blue a", 0.4578030974f, placed_glyph_blues[0]);
  assert_float("placed glyph blue b", 0.8177569126f, placed_glyph_blues[1]);
  assert_float("placed glyph blue c", 0.4994471018f, placed_glyph_blues[2]);
  assert_float("placed glyph blue d", 0.6124764171f, placed_glyph_blues[3]);
  assert_float("placed glyph blue e", 0.3621127009f, placed_glyph_blues[4]);
  assert_float("placed glyph blue f", 0.2592586932f, placed_glyph_blues[5]);
  assert_float("placed glyph blue g", 0.9147162815f, placed_glyph_blues[6]);
  assert_float("placed glyph blue h", 0.0459671612f, placed_glyph_blues[7]);
  assert_float("placed glyph blue i", 0.0194627529f, placed_glyph_blues[8]);
  assert_float("placed glyph blue j", 0.2956948430f, placed_glyph_blues[9]);
  assert_float("placed glyph blue k", 0.3117195449f, placed_glyph_blues[10]);

  return exit_code;
}
