#include "wrap_text.h"
#include "text_font.h"
#include "written_text.h"
#include <stdbool.h>

void wrap_text(const int width, written_text *const written_text) {
  int number_of_code_points_in_current_word = 0;
  int width_of_current_word = 0;
  int width_of_current_line = 0;
  int spacing_between_beginning_of_word_and_preceding_white_space = 0;
  int previous_code_point_spacing = -1;
  bool possible_to_insert_new_line_before_current_word = false;

  for (int index = 0; index < written_text->number_of_written_code_points; index++) {
    const int glyph_index = written_text->written_glyph_indices[index];

    if (glyph_index == -1) {
      if (possible_to_insert_new_line_before_current_word && number_of_code_points_in_current_word > 0 && width_of_current_line + spacing_between_beginning_of_word_and_preceding_white_space + width_of_current_word > width) {
        written_text->written_glyph_indices[index - number_of_code_points_in_current_word - 1] = -1;
      }

      number_of_code_points_in_current_word = 0;
      width_of_current_word = 0;
      width_of_current_line = 0;
      previous_code_point_spacing = -1;
      possible_to_insert_new_line_before_current_word = false;
    } else {
      const text_font *const text_font = written_text->written_text_fonts[index];
      const int code_point_spacing = text_font->code_point_spacing;
      const int applicable_glyph_spacing = previous_code_point_spacing == -1 ? 0 : (code_point_spacing > previous_code_point_spacing ? code_point_spacing : previous_code_point_spacing);
      const int glyph_width = text_font->glyph_widths[glyph_index];

      if (text_font->glyph_code_points[glyph_index] == 32) {
        if (number_of_code_points_in_current_word > 0) {
          if (possible_to_insert_new_line_before_current_word && width_of_current_line + spacing_between_beginning_of_word_and_preceding_white_space + width_of_current_word > width) {
            written_text->written_glyph_indices[index - number_of_code_points_in_current_word - 1] = -1;
            width_of_current_line = width_of_current_word + applicable_glyph_spacing + glyph_width;
          } else {
            width_of_current_line += spacing_between_beginning_of_word_and_preceding_white_space + width_of_current_word + applicable_glyph_spacing + glyph_width;
          }

          number_of_code_points_in_current_word = 0;
          width_of_current_word = 0;
        } else {
          width_of_current_line += applicable_glyph_spacing + glyph_width;
        }

        if (width_of_current_line > width) {
          width_of_current_line = 0;
          previous_code_point_spacing = -1;
          possible_to_insert_new_line_before_current_word = false;
          written_text->written_glyph_indices[index] = -1;
        } else {
          previous_code_point_spacing = code_point_spacing;
          possible_to_insert_new_line_before_current_word = true;
        }
      } else {
        number_of_code_points_in_current_word++;

        if (number_of_code_points_in_current_word == 1) {
          spacing_between_beginning_of_word_and_preceding_white_space = applicable_glyph_spacing;
          width_of_current_word = glyph_width;
        } else {
          width_of_current_word += applicable_glyph_spacing + glyph_width;
        }

        previous_code_point_spacing = code_point_spacing;
      }
    }
  }
}
