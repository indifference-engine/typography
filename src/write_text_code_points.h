#ifndef WRITE_TEXT_CODE_POINTS_H

#define WRITE_TEXT_CODE_POINTS_H

#include <stdbool.h>
#include <stdint.h>
#include "text_font.h"
#include "written_text.h"

/**
 * Appends a null-terminated sequence of code points to an item of text being
 * composed.
 * @param code_points The null-terminated sequence of UTF-32 code points to
 *                    append.  LF/0A/10 is passed to write_text_new_line.
 * @param text_font The font to use.
 * @param opacity The opacity of the code point, where 0 is fully transparent
 *                and 1 is fully opaque.  Behavior for values outside this
 *                range, including NaN, is undefined.
 * @param red The intensity of the red channel of the code point.  Behavior is
 *            undefined if NaN, infinity, negative infinity or unable to be cast
 *            to int.
 * @param green The intensity of the green channel of the code point.  Behavior
 *              is undefined if NaN, infinity, negative infinity or unable to be
 *              cast to int.
 * @param blue The intensity of the blue channel of the code point.  Behavior is
 *             undefined if NaN, infinity, negative infinity or unable to be
 *             cast to int.
 * @param written_text The state to append to.  Some code points may be appended
 *                     even if the operation does not succeed.
 * @return True when the operation succeeds, otherwise, false.
 */
bool write_text_code_points(
    const uint32_t *const code_points,
    const text_font *const text_font,
    const float opacity,
    const float red,
    const float green,
    const float blue,
    written_text *const written_text);

#endif
