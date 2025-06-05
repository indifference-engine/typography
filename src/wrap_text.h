#ifndef WRAP_TEXT_H

#define WRAP_TEXT_H

#include "written_text.h"

/**
 * Replaces space characters with newline characters to fit previously written
 * text within a given width.
 * @param width The width within which to fit the previously written text.
 * @param written_text The previously written text to wrap.
 */
void wrap_text(const int width, written_text *const written_text);

#endif
