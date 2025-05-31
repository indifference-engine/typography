#ifndef WRITE_TEXT_NEW_LINE_H

#define WRITE_TEXT_NEW_LINE_H

#include <stdbool.h>
#include "text_font.h"
#include "written_text.h"

/**
 * Appends a new-line character to an item of text being composed.
 * @param written_text The state to append to.  Not modified unless the
 *                     operation succeeds.
 * @return True when the operation succeeds, otherwise, false.
 */
bool write_text_new_line(written_text *const written_text);

#endif
