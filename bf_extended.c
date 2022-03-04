#include <stdio.h>

// Memory size of Brainfuck programs
#define MEM_SIZE 30000

// Vanilla Brainfucks commands
#define PTR_LEFT '<'
#define PTR_RIGHT '>'
#define PTR_INCREMENT '+'
#define PTR_DECREMENT '-'
#define CHAR_IN ','
#define CHAR_OUT '.'
#define BF_LOOP_START '['
#define BF_LOOP_END ']'

// Extended commands
#define MULTIPLY '*'
#define DIVIDE '/'
#define PTR_VALUE '#'
#define FOR_LOOP_START '{'
#define FOR_LOOP_END '}'
#define EXIT '~'

int for_loop();
int run(char);

char mem[MEM_SIZE] = {0};
FILE * fp;
char * ptr;

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

  char char_in = fgetc(fp);

  if (char_in >= '0' && char_in <= '9') {

    fseek(fp, -1, SEEK_CUR);
    int num_in = fscanf(fp, "%d", value);
    if (num_in == 1) {return 1;}

  } else if (char_in == PTR_VALUE) {

    int integer_in = 0;
    int num_in = fscanf(fp, "%d\n", &integer_in);

    if (num_in == 1) {
      *value = mem[integer_in];
    } else {
      *value = *ptr;
    }

    return 1;
  }

  fseek(fp, -1, SEEK_CUR);
  return 0;
} /* get_ptr_value() */



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
  const long int for_end_index = ftell(fp);

  int num_repititions = 0;
  int num_in = read_args(&num_repititions);

  const long int final_position = ftell(fp);

  if (num_in != 1) {
    printf("\n\nSyntax Error:\n\nFile pointer index: %ld\n", ftell(fp));
    printf("Expected an integer after '}' for loop closing bracket. ( e.g. {}3 for 3 iterations)\n\n");
    return EOF;
  }

  fseek(fp, for_end_index, SEEK_SET);

  int close_counter = 0;

  do {
    fseek(fp, -2, SEEK_CUR);
    char char_in = fgetc(fp);
    if (char_in == FOR_LOOP_END) {
      close_counter++;
    } else if ((char_in == FOR_LOOP_START) && (close_counter > 0)) {
      close_counter--;
    } else if ((char_in == FOR_LOOP_START) && (close_counter == 0)) {
      break;
    }
  } while(1 == 1);

  long int for_start_index = ftell(fp);

  for(int i = 1; i < num_repititions; i++) {
    fseek(fp, for_start_index, SEEK_SET);
    char next = fgetc(fp);
    do {
      run(next);
      next = fgetc(fp);
    } while(next != FOR_LOOP_END);
  }

  fseek(fp, final_position, SEEK_SET);

  return 0;
} /* for_loop() */

int run(char command) {

  int value = 0;

  switch(command) {

    case PTR_LEFT:
      if (read_args(&value) == 1) {
        ptr -= value;
      } else {
        ptr--;
      }
      break;

    case PTR_RIGHT:
      if (read_args(&value) == 1) {
        ptr += value;
      } else {
        ptr++;
      }
      break;

    case PTR_INCREMENT:
      if (read_args(&value) == 1) {
        (*ptr)+= value;
      } else {
        (*ptr)++;
      }
      break;

    case PTR_DECREMENT:
      if (read_args(&value) == 1) {
        (*ptr)-= value;
      } else {
        (*ptr)--;
      }
      break;

    case CHAR_IN:
      printf("Input a character: ");
      scanf(" %c", ptr);
      break;

    case CHAR_OUT:
      printf("%c", *ptr);
      break;

    case BF_LOOP_START:
      if (*ptr == 0) {
        int start_counter = 0;
        do {
          char start_in = fgetc(fp);
          if (start_in == BF_LOOP_START) {
            start_counter++;
          } else if ((start_in == BF_LOOP_END) && (start_counter > 0)) {
            start_counter--;
          } else if ((start_in == BF_LOOP_END) && (start_counter == 0)) {
            fseek(fp, 1, SEEK_CUR);
            break;
          }
        } while(1 == 1);
      }
      break;

    case BF_LOOP_END:
      if (*ptr != 0) {
        int close_counter = 0;
        do {
          fseek(fp, -2, SEEK_CUR);
          char end_in = fgetc(fp);
          if (end_in == BF_LOOP_END) {
            close_counter++;
          } else if ((end_in == BF_LOOP_START) && (close_counter > 0)) {
            close_counter--;
          } else if ((end_in == BF_LOOP_START) && (close_counter == 0)) {
            break;
          }
        } while(1 == 1);
        fseek(fp, -1, SEEK_CUR);
      }
      break;

    /* ------------------------------------------------------------------------- */
    /*     End of vanilla brainfuck commands, and start of extended commands.    */
    /* ------------------------------------------------------------------------- */

    case MULTIPLY:
      if (read_args(&value) == 1) {
        (*ptr)*= value;
      } else {
        printf("\n\nSyntax Error:\n\nFile pointer index: %ld\n", ftell(fp));
        printf("Expected integer value after '*' (multiplication) operator.\n\n");
        return EOF;
      }
      break;

    case DIVIDE:
      if (read_args(&value) == 1) {
        (*ptr)/= value;
      } else {
        printf("\n\nSyntax Error:\n\nFile pointer index: %ld\n", ftell(fp));
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

      printf("\n\nSyntax Error:\n\nFile pointer index: %ld\n", ftell(fp));
      printf("Using '#' (pointer value) operator is only permitted after commands that take integer arguments (e.g. +x, -x, <x, >x, *x, /x, {}x) OR with the '.' (CHAR_OUT) operator directly afterwards. (e.g. #. , #2.) \n\n");

      return EOF;

    case FOR_LOOP_START:
      break;

    case FOR_LOOP_END:
      return for_loop();
      break;

    case EXIT:
    case EOF:
      return EOF;
  }

  return 0;
} /* run() */

int main(int argc, char **argv) {

  ptr = mem;

  if (argc < 2) {
    printf("\n\nError: Specify a Brainfuck file to interpret.\n\n");
    return -1;
  }

  fp = fopen(argv[1], "r");
  if (!fp) {
    printf("\n\nError: Brainfuck file '%s' not found.\n\n", argv[1]);
    return -1;
  }

  while (run(fgetc(fp)) != EOF){continue;}

  fclose(fp);
  fp = NULL;

  return 0;
} /* main() */