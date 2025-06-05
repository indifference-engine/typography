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

  const int height = measure_text_height(written);

  if (height != 0)
  {
    fprintf(stderr, "Expected 0, actual %d.\n", height);
    return 1;
  }

  return 0;
}
