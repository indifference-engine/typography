#include <stdio.h>
#include <stdint.h>
#include "../../src/text_font.h"
#include "../../src/written_text.h"
#include "../../src/start_text.h"
#include "../../src/write_text_code_point.h"
#include "../../src/write_text_new_line.h"
#include "../../src/measure_text_height.h"

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

  const int height = measure_text_height(written);

  if (height != 240)
  {
    fprintf(stderr, "Expected 240, actual %d.\n", height);
    return 1;
  }

  return 0;
}
