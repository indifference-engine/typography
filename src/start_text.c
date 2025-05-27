#include "written_text.h"
#include "start_text.h"

written_text start_text(
    const int number_of_writable_code_points,
    const text_font **const written_text_fonts,
    int *const written_glyph_indices,
    float *const written_opacities,
    float *const written_reds,
    float *const written_greens,
    float *const written_blues)
{
  const written_text output = {
      .number_of_written_code_points = 0,
      .number_of_writable_code_points = number_of_writable_code_points,
      .written_text_fonts = written_text_fonts,
      .written_glyph_indices = written_glyph_indices,
      .written_opacities = written_opacities,
      .written_reds = written_reds,
      .written_greens = written_greens,
      .written_blues = written_blues};

  return output;
}
