/* BOLOGNA LANGUAGE INTERPRETER
 * =============================
 *
 * Bologna is an esoteric, interpreted language
 * made to see what is possible with a minimilastic
 * programming paradigm.
 *
 * OSS under the MIT License.
 */

/*----------------------------------------------------------------*/

#include <stdio.h>
#include <stdint.h>

#include "bologna_interpreter.h"

/*----------------------------------------------------------------*/

// Memory array
uint8_t mem[MEM_SIZE] = { 0 };

// Main memory pointer (the one that gets moved/read)
uint8_t * ptr;

// File pointer
FILE * fp;

// Marker to indicate whether parsing a comment or commands
int is_comment = 0;



/*
 * Line printed for every error regardless of type.
 * Displays the file pointer index along with error message.
 */

void print_error() {
  printf("\n\nSyntax Error:\n\nFile pointer index: %ld\n", ftell(fp));
} /* print_error() */



/*
 * Reads arguments passed to commands that take them.
 *
 * Let x be some integer argument:
 *
 * +x, -x, <x, >x, *x, /x, {}x, #x, +#x, -#x,...
 *
 * This function takes the integer value x and applies it
 *
 * EX:
 *
 * '-7' Subtracts 7 from the current pointer value.
 *
 * '-#7' Takes the current pointer value and subtracts the value at mem[index 7]
 */
int read_args(int * value) {

  int char_in =  fgetc(fp);

  // If the argument is just an integer
  if (char_in >= '0' && char_in <= '9') {

    // Seek back one character since we may have taken only one digit of a longer integer
    fseek(fp, -1, SEEK_CUR);

    // Read in the argument integer
    int num_in = fscanf(fp, "%d", value);

    // If argument was read in, return success
    if (num_in == 1) {return 1;} else {return 0;}

  // If the argument was a memory index operator (#x)
  } else if (char_in == PTR_VALUE) {

    // Number to store memory index
    int integer_in = 0;

    // Read in the integer representing the memory index
    int num_in = fscanf(fp, "%d\n", &integer_in);

    // If mem index was read in successfully
    if (num_in == 1) {
      // Give the value to the value at the memory index
      *value = mem[integer_in];
    } else {
      // Give the value of the current memory index
      *value = *ptr;
    }

    return 1;

  // If the character read in was neither (0-9) or '#x' and not at end of file
  } else if (feof(fp) == 0) {
    // Seek back one (This character is the start of a new command)
    fseek(fp, -1, SEEK_CUR);
  }

  return 0;
} /* read_args() */



/*
 * Function for processing "for loops"
 * Let x denote the number of iterations.
 *
 * Syntax: {>++-<-.,}x
 *
 * EX: {+}8
 *
 * Adds 1 to the ptr value 8 times.
 */

int for_loop() {

  // Get the index of the end of the foor loop
  const long int for_end_index = ftell(fp);

  int num_repititions = 0;

  // Read the argument 'x' passed to the for loop, i.e.'{}x'
  int num_in = read_args(&num_repititions);

  // Get the index of the final position of the loop (after the argument)
  const long int final_position = ftell(fp);

  // If no argument was given to the loop, throw an error
  if (num_in != 1) {
    print_error();
    printf("Expected an integer after '}' for loop closing bracket. ( e.g. {}3 for 3 iterations)\n\n");
    return EOF;
  }

  // Seek to end of for loop
  fseek(fp, for_end_index, SEEK_SET);

  int close_counter = 0;

  // Count the '}' and '{' braces while traversing to find the matching brace (in case of nested loops)
  do {
    fseek(fp, -2, SEEK_CUR);
    char char_in = fgetc(fp);
    if (char_in == BRACE_END) {
      close_counter++;
    } else if ((char_in == BRACE_START) && (close_counter > 0)) {
      close_counter--;
    } else if ((char_in == BRACE_START) && (close_counter == 0)) {
      break;
    }
  } while(1 == 1);

  // Get the index of the start of the for loop
  long int for_start_index = ftell(fp);

  // Repeat as many times as number of repetitions (specified by argument)
  for(int i = 1; i < num_repititions; i++) {

    // Seek to beginning of loop on each execution
    fseek(fp, for_start_index, SEEK_SET);

    // Run code inside of for loop
    char next = fgetc(fp);
    do {
      if (run(next) == EOF) {
        return EOF;
      }
      next = fgetc(fp);
    } while(next != BRACE_END);
  }

  // Seek past the end of the for loop, including past the numerical argument at the end.
  fseek(fp, final_position, SEEK_SET);

  return 0;
} /* for_loop() */



/*
 * Query is Bologna's only logical command.
 * Denoted "?( logical expression ){ code }"
 *
 * Code is only ran if the logical expression is true.
 */

int query() {

  char logical_operator = fgetc(fp);

  // Expect an opening parenthese after the logical expression
  if (logical_operator == '(') {
    int first_value = 0;

    // Read the integer value of the first argument of the logical expression
    if (read_args(&first_value) == 1) {

      //Get logical operator (<, >, =, !)
      logical_operator = fgetc(fp);

      int second_value = 0;

      // Read the integer value of the second argument of the logical expression
      if ((read_args(&second_value) == 1) && (feof(fp) == 0)) {

        // Integer that keeps track of whether the code inside the braces should be run later
        int condition_met = 0;

        // Switch on the logical operator to use correct associated logic
        switch(logical_operator) {
          case LESS_THAN:
            if(first_value < second_value){
              condition_met = 1;
            }
            break;

          case GREATER_THAN:
            if (first_value > second_value) {
              condition_met = 1;
            }
            break;

          case EQUAL:
            if (first_value == second_value) {
              condition_met = 1;
            }
            break;

          case NOT:
            if (first_value != second_value) {
              condition_met = 1;
            }
            break;
        }

        char char_in = '\0';

        // Condition was met. Run code in between '{ }' braces
        if (condition_met == 1) {

          fseek(fp, 2, SEEK_CUR);

          char_in = fgetc(fp);

          // Execute code inside of braces
          do {
            if(run(char_in) == EOF){
              return EOF;
            }
            char_in = fgetc(fp);
          } while((feof(fp) == 0) && (char_in != BRACE_END));

        // Condition was not met, traverse to closing brace '}' without running code inside
        } else {

          int open_brace_counter = 0;

          fseek(fp, 2, SEEK_CUR);

          // Traverse to closing brace, skipping over execution of code in-between
          do {
            char_in = fgetc(fp);
            if (char_in == BRACE_START) {
              open_brace_counter++;
            } else if (char_in == BRACE_END) {
              open_brace_counter--;
            }
          } while((feof(fp) == 0) && ((char_in != BRACE_END) || (open_brace_counter >= 0)));

        }

        return 0;

      }
    }

  }
  print_error();
  printf("Expected Query in the form of '?(a<b){}' - Check for extraneous whitespace or characters.\n\n");
  return EOF;
} /* query() */



/*
 * Executes input commands from a file.
 * Takes in a char representing the command and runs
 * the associated processing for the given command.
 *
 * Returns: 0 for successful command execution, EOF for error
 */

int run(char command) {

  if ((feof(fp) != 0) || (ferror(fp) != 0)){
    return EOF;
  }

  int value = 0;

   if (is_comment == 1) {
    if (command == COMMENT) {
      is_comment = 0;
    }
    return 0;
  }

  switch(command) {

    case COMMENT:
      is_comment = 1;
      break;

    case PTR_LEFT_SHIFT:
      if (read_args(&value) == 1) {
        if (ptr - value < mem) {
          ptr = mem;
        } else {
          ptr -= value;
        }
      } else {
        if (ptr - 1 > mem) {
          ptr--;
        }
      }
      break;

    case PTR_RIGHT_SHIFT:
      if (read_args(&value) == 1) {
        if (ptr + value > mem + MEM_SIZE) {
          ptr = mem + MEM_SIZE - 1;
        } else {
          ptr += value;
        }
      } else {
        if (ptr + 1 < mem + MEM_SIZE) {
          ptr++;
        }
      }
      break;

    case INCREMENT:
      if (read_args(&value) == 1) {
        (*ptr)+= value;
      } else {
        (*ptr)++;
      }
      break;

    case DECREMENT:
      if (read_args(&value) == 1) {
        (*ptr)-= value;
      } else {
        (*ptr)--;
      }
      break;

    case CHAR_IN:
      scanf(" %hhd", ptr);
      break;

    case CHAR_OUT:
      if (read_args(&value) == 1) {
        for (int i = 0; i < value; i++) {
          printf("%c", *ptr);
        }
      } else {
        printf("%c", *ptr);
      }
      break;

    case BRN_FCK_LOOP_START:
      if (*ptr == 0) {
        int start_counter = 0;
        do {
          char start_in = fgetc(fp);
          if (start_in == BRN_FCK_LOOP_START) {
            start_counter++;
          } else if ((start_in == BRN_FCK_LOOP_END) && (start_counter > 0)) {
            start_counter--;
          } else if ((start_in == BRN_FCK_LOOP_END) && (start_counter == 0)) {
            fseek(fp, 1, SEEK_CUR);
            break;
          }
        } while(1 == 1);
      }
      break;

    case BRN_FCK_LOOP_END:
      if (*ptr != 0) {
        int close_counter = 0;
        do {
          fseek(fp, -2, SEEK_CUR);
          char end_in = fgetc(fp);
          if (end_in == BRN_FCK_LOOP_END) {
            close_counter++;
          } else if ((end_in == BRN_FCK_LOOP_START) && (close_counter > 0)) {
            close_counter--;
          } else if ((end_in == BRN_FCK_LOOP_START) && (close_counter == 0)) {
            break;
          }
        } while(1 == 1);
      }
      break;

    /* ------------------------------------------------------------------------- */
    /*     End of vanilla brainfuck commands, and start of extended commands.    */
    /* ------------------------------------------------------------------------- */

    case ZERO:
      (*ptr) = 0;
      break;

    case ABSOLUTE_SHIFT:
      if (read_args(&value) == 1) {
        ptr = mem + value;
      } else {
        print_error();
        printf("Expected integer value after ':' (Absolute shift) operator.\n\n");
        return EOF;
      }

      break;

    case MULTIPLY:
      if (read_args(&value) == 1) {
        (*ptr)*= value;
      } else {
        print_error();
        printf("Expected integer value after '*' (multiplication) operator.\n\n");
        return EOF;
      }
      break;

    case DIVIDE:
      if (read_args(&value) == 1) {
        (*ptr)/= value;
      } else {
        print_error();
        printf("Expected integer value after '/' (integer division) operator.\n\n");
        return EOF;
      }
      break;

    case PTR_VALUE:
      fseek(fp, -1, SEEK_CUR);
      if (read_args(&value) == 1) {
        char in = fgetc(fp);
        if (in == CHAR_OUT) {
          printf("%c", value);
          break;
        }
      }

      print_error();
      printf("Using '#' (pointer value) operator is only permitted after commands that take integer arguments (e.g. +x, -x, <x, >x, *x, /x, {}x) OR with the '.' (CHAR_OUT) operator directly afterwards. (e.g. #. , #2.) \n\n");
      return EOF;

    case QUERY:
      return query();
      break;

    case BRACE_START:
      break;

    case BRACE_END:
      return for_loop();
      break;

    case EXIT:
    case EOF:
      return EOF;
  }

  return 0;
} /* run() */



/*
 * Main function: contains interpreter loop and file argument handling
 */

int main(int argc, char **argv) {

  // Start the pointer at index 0 of memory
  ptr = mem;

  // If no filename argument was passed, throw error
  if (argc < 2) {
    printf("\n\nError: Specify a Brainfuck file to interpret.\n\n");
    return -1;
  }

  // If the given file does not exist or cannot be opened, throw error
  fp = fopen(argv[1], "r");
  if (!fp) {
    printf("\n\nError: Brainfuck file '%s' not found.\n\n", argv[1]);
    return -1;
  }

  // Run while EOF is not reached and run() doesn't throw error (Returns EOF for error)
  while (run(fgetc(fp)) != EOF){continue;}

  // Close file
  fclose(fp);
  fp = NULL;

  return 0;
} /* main() */