#ifndef WRITE_TEXT_INT_H

#define WRITE_TEXT_INT_H

#include <stdbool.h>
#include "text_font.h"
#include "written_text.h"

/**
 * Appends an integer to an item of text being composed.
 * @param value The integer to append.
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
bool write_text_int(
    const int value,
    const text_font *const text_font,
    const float opacity,
    const float red,
    const float green,
    const float blue,
    written_text *const written_text);

#endif
