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

  int written_glyph_indices[7];
  text_state state = start_text(7, written_glyph_indices);

  if (!write_text_code_point(204668171, &state))
  {
    fprintf(stderr, "Unexpectedly failed to write first code point.\n");
    return 1;
  }

  if (!write_text_code_point(505255796, &state))
  {
    fprintf(stderr, "Unexpectedly failed to write second code point.\n");
    return 1;
  }

  if (!write_text_code_point(204668171, &state))
  {
    fprintf(stderr, "Unexpectedly failed to write third code point.\n");
    return 1;
  }

  if (!write_text_code_point(402862483, &state))
  {
    fprintf(stderr, "Unexpectedly failed to write fourth code point.\n");
    return 1;
  }

  if (!write_text_code_point(358868195, &state))
  {
    fprintf(stderr, "Unexpectedly failed to write fifth code point.\n");
    return 1;
  }

  if (!write_text_code_point(505255796, &state))
  {
    fprintf(stderr, "Unexpectedly failed to write sixth code point.\n");
    return 1;
  }

  if (!write_text_code_point(204668171, &state))
  {
    fprintf(stderr, "Unexpectedly failed to write seventh code point.\n");
    return 1;
  }

  if (write_text_code_point(358868195, &state))
  {
    fprintf(stderr, "Unexpectedly succeeded in writing eighth code point.\n");
    return 1;
  }

  return 0;
}
