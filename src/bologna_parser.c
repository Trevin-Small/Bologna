/* BOLOGNA LANGUAGE PARSER
 * =============================
 *
 * Bologna is an esoteric, interpreted language
 * made to see what is possible with a minimilastic
 * programming paradigm.
 *
 * OSS under the MIT License.
 *
 * Bologna Parser takes a Bologna file and reduces it
 * to just its command characters, elimininating comments,
 * whitespace, linebreaks, and any other extraneous characters.
 *
 * This improves interpreter performance of 'bologna_interpreter.c'.
 */

/*----------------------------------------------------------------*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "bologna.h"

/*----------------------------------------------------------------*/

void close_files(FILE **fr, FILE **fw) {
  fclose(*fr);
  *fr = NULL;
  fclose(*fw);
  *fw = NULL;
} /* close_files() */



/*
 * Reads arguments passed to commands, and returns the integer values passed.
 *
 * Takes in a file read pointer, and an operator character (i.e.  ><.,+-.,#)
 */
int operator_args(FILE *fr, char operator_char) {
  int value = 0;

  if (operator_char == PTR_VALUE) {

    // Read in the integer representing the memory index
    int num_in = fscanf(fr, "%d\n", &value);

    // If mem index was read in successfully
    if (num_in == 1) {
      // Give the value to the value at the memory index
      return value;
    } else {
      // Give the value of the current memory index
      value = -1;
    }

    // If the argument is just an integer
  } else if (fscanf(fr, "%d", &value) == 1) {
    return value;
  }

  return -1;
} /* read_args() */



/*
 * Condenses a file by removing comments, whitespace, and any other
 * non-command characters. Creates a new minimized output file.
 */

int file_condense(FILE *fr, FILE *fw) {
  int is_comment = 0;
  int argument = 0;
  char operator_char = '\0';
  while ((feof(fr) == 0) && (ferror(fr) == 0) && (ferror(fw) == 0)) {
    operator_char = fgetc(fr);

    if (is_comment == 1) {

      if (operator_char == COMMENT) {
        is_comment = 0;
      }
      continue;

    } else {

      switch(operator_char) {

        case COMMENT:
          is_comment = 1;
          break;


        // Operators that do not take arguments
        case ZERO:
        case CHAR_IN:
        case BRACE_START:
        case QUERY:
        case LOGIC_START:
        case LOGIC_END:
        case EQUAL:
        case NOT:
          fputc(operator_char, fw);
          break;


        // Arguments that do take operators
        case PTR_LEFT_SHIFT:
        case PTR_RIGHT_SHIFT:
        case INCREMENT:
        case DECREMENT:
        case CHAR_OUT:
        case BRN_FCK_LOOP_START:
        case BRN_FCK_LOOP_END:
        case ABSOLUTE_SHIFT:
        case MULTIPLY:
        case DIVIDE:
        case PTR_VALUE:
        case BRACE_END:
        case EXIT:
          fputc(operator_char, fw);
          argument = operator_args(fr, operator_char);
          if (argument != -1) {
            fprintf(fw, "%d", argument);
          }
          break;

        default:
          continue;
      }

    }
  }

  if ((feof(fr) == 1)) {
    return 0;
  }

  return -1;
} /* file_condense() */

/*----------------------------------------------------------------*/



int main(int argc, char **argv) {

  // If no filename argument was passed, throw error
  if (argc < 2) {
    printf("\n\nError: Specify a Brainfuck file to interpret.\n\n");
    return -1;
  }

  FILE * fr;
  FILE * fw;

  // If the given file does not exist or cannot be opened, throw error
  fr = fopen(argv[1], "r");
  if (!fr) {
    printf("\n\nError: Brainfuck file '%s' not found.\n\n", argv[1]);
    return -1;
  }

  fw = fopen(argv[2], "w");
  if (!fr) {
    printf("\n\nError: Unable to create file '%s'\n\n", argv[1]);
    return -1;
  }

  if (file_condense(fr, fw) == -1) {
    printf("\n\nError: Error condesing file '%s'.\n\n", argv[1]);
    close_files(&fr, &fw);
    return -1;
  }


  return 0;
}