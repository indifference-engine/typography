# Math

C library for simple text layout.

## Usage

- First, collect the information needed to populate a `text_font`.
- Next, call `start_text` to wrap buffers into state which will track written
  text.
- Call `write_text_code_point` to build up the item of text.
- Finally, call `place_text` to calculate the final list of glyphs.

### Project Level

Your application's build pipeline will need to be configured to compile each C
file in the [src](./src) directory and recompile every C file should any H files
change.  Then, include each H file in the same directory to make its
corresponding function available.

### Assumptions

- The compilation environment supports C99.
- No float arguments:
  - Are NaN.
  - Are infinity.
  - Are negative infinity.
  - Cannot be cast to `int` without undefined behavior (for example, very large
    values).

### Types

| Name           | Description                                          |
| -------------- | ---------------------------------------------------- |
| `text_font`    | A collection of glyphs forming a font.               |
| `written_text` | State which tracks the creation of an item of text.  |
| `placed_text`  | Final coordinates for glyphs within an item of text. |

### Functions

| Name                    | Description                                                      |
| ----------------------- | ---------------------------------------------------------------- |
| `start_text`            | Initializes state to start producing an item of text.            |
| `write_text_code_point` | Appends a code point to an item of text being composed.          |
| `place_text`            | Calculates final co-ordinates for glyphs within an item of text. |

## Tests

Execute `make` to run the test suite.

### Dependencies

- Make.
- MinGW-GCC for Windows, Clang for all other platforms.
- Bash.
