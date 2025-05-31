#include <stdbool.h>
#include <stdint.h>
#include "text_font.h"
#include "written_text.h"
#include "write_text_code_points.h"
#include "write_text_code_point.h"

bool write_text_code_points(
    const uint32_t *const code_points,
    const text_font *const text_font,
    const float opacity,
    const float red,
    const float green,
    const float blue,
    written_text *const written_text)
{
  bool output = true;
  int index = 0;

  while (true)
  {
    const uint32_t code_point = code_points[index];

    if (code_point == 0)
    {
      return output;
    }

    if (!write_text_code_point(code_point, text_font, opacity, red, green, blue, written_text))
    {
      output = false;
    }

    index++;
  }
}
