#ifndef WRITE_TEXT_NEW_LINE_H

#define WRITE_TEXT_NEW_LINE_H

#include <stdbool.h>
#include "text_font.h"
#include "written_text.h"

/**
 * Appends a new-line character to an item of text being composed.
 * @param text_font The font to use.
 * @param written_text The state to append to.  Not modified unless the
 *                     operation succeeds.
 * @return True when the operation succeeds, otherwise, false.
 */
bool write_text_new_line(
    const text_font *const text_font,
    written_text *const written_text);

#endif
