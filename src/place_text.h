#ifndef PLACE_TEXT_H

#define PLACE_TEXT_H

#include "written_text.h"
#include "placed_text.h"

/**
 * The text is placed below the anchor.
 */
#define BELOW_TEXT_ANCHOR 0

/**
 * The text is placed above the anchor.
 */
#define ABOVE_TEXT_ANCHOR 2

/**
 * The text is to be placed right of the anchor.
 */
#define RIGHT_OF_TEXT_ANCHOR 0

/**
 * The text is placed over the anchor.
 */
#define CENTERED_ON_TEXT_ANCHOR 1

/**
 * The text is placed left of the anchor.
 */
#define LEFT_OF_TEXT_ANCHOR 2

/**
 * Calculates final co-ordinates for glyphs within an item of text.
 * @param written_text The text state to place.
 * @param vertical_alignment The vertical alignment of the text.
 * @param horizontal_alignment The horizontal alignment of the text.
 * @param placed_text The placed text; emptied and written to when the operation
 *                    succeeds.  Content is undefined when the operation does
 *                    not succeed.
 * @return The number of placed glyphs when the operation succeeds.  -1 when the
 *         operation does not succeed.
 */
int place_text(
    const written_text written_text,
    const int vertical_alignment,
    const int horizontal_alignment,
    placed_text *const placed_text);

#endif
