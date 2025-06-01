#include <stdbool.h>
#include "text_font.h"
#include "written_text.h"
#include "write_text_code_point.h"

static bool recurse_remainder(
    const int value,
    const text_font *const text_font,
    const float opacity,
    const float red,
    const float green,
    const float blue,
    written_text *const written_text)
{
  if (value > 0)
  {
    bool output = recurse_remainder(value / 10, text_font, opacity, red, green, blue, written_text);
    return write_text_code_point(48 + (value % 10), text_font, opacity, red, green, blue, written_text) && output;
  }
  else
  {
    return true;
  }
}

bool write_text_int(
    const int value,
    const text_font *const text_font,
    const float opacity,
    const float red,
    const float green,
    const float blue,
    written_text *const written_text)
{
  if (value < 0)
  {
    bool output = write_text_code_point(45, text_font, opacity, red, green, blue, written_text);
    return recurse_remainder(-value, text_font, opacity, red, green, blue, written_text) && output;
  }
  else if (value > 0)
  {
    return recurse_remainder(value, text_font, opacity, red, green, blue, written_text);
  }
  else
  {
    return write_text_code_point(48, text_font, opacity, red, green, blue, written_text);
  }
}
