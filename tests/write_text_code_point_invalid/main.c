#include <stdio.h>
#include <stdint.h>
#include "../../src/text_font.h"
#include "../../src/text_state.h"
#include "../../src/start_text.h"
#include "../../src/write_text_code_point.h"

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
  text_state state = start_text(7, written_text_fonts, written_glyph_indices, written_opacities, written_reds, written_greens, written_blues);

  const int glyph_widths_a[] = {23, 18, 19, 25};
  const uint32_t glyph_code_points_a[] = {505255796, 204668171, 358868195, 402862483};

  const text_font font_a = {
      .code_point_spacing = 5,
      .line_spacing = 3,
      .line_height = 12,
      .glyph_widths = glyph_widths_a,
      .glyph_code_points = glyph_code_points_a,
      .number_of_glyphs = 4};

  const int glyph_widths_b[] = {50, 49, 37};
  const uint32_t glyph_code_points_b[] = {204668171, 505255796, 37498374};

  const text_font font_b = {
      .code_point_spacing = 41,
      .line_spacing = 25,
      .line_height = 17,
      .glyph_widths = glyph_widths_b,
      .glyph_code_points = glyph_code_points_b,
      .number_of_glyphs = 3};

  if (!write_text_code_point(204668171, &font_a, 0.1564262168f, 0.0437286089f, 0.2452098142f, 0.4578030974f, &state))
  {
    fprintf(stderr, "Unexpectedly failed to write first code point.\n");
    return 1;
  }

  if (!write_text_code_point(505255796, &font_b, 0.3664873978f, 0.8843461135f, 0.0204608919f, 0.8177569126f, &state))
  {
    fprintf(stderr, "Unexpectedly failed to write second code point.\n");
    return 1;
  }

  if (!write_text_code_point(204668171, &font_b, 0.5377511140f, 0.6091213575f, 0.3598658273f, 0.4994471018f, &state))
  {
    fprintf(stderr, "Unexpectedly failed to write third code point.\n");
    return 1;
  }

  if (write_text_code_point(402862481, &font_a, 0.4555927370f, 0.7303668130f, 0.0712067199f, 0.5033791132f, &state))
  {
    fprintf(stderr, "Unexpectedly succeeded in writing fourth code point.\n");
    return 1;
  }

  return 0;
}
