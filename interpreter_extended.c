#include <stdio.h>

// Memory size of Brainfuck programs
#define MEM_SIZE 30000
#define TEN_KILOBYTE 10000

// All of Brainfucks commands.... only 8 lines LOL
#define PTR_LEFT '<'
#define PTR_RIGHT '>'
#define PTR_INCREMENT '+'
#define PTR_DECREMENT '-'
#define CHAR_IN ','
#define CHAR_OUT '.'
#define BF_LOOP_START '['
#define BF_LOOP_END ']'
#define FOR_LOOP_START '{'
#define FOR_LOOP_END '}'

int for_loop();
int run(char);

char mem[MEM_SIZE] = {0};
FILE * fp;
char * ptr;

int for_loop() {
  long int for_end_index = ftell(fp);
  int num_repititions = 0;
  int num_in = fscanf(fp, "%d", &num_repititions);

  long int size_of_repititions = ftell(fp) - for_end_index;

  if (num_in != 1) {
    printf("Expected an integer after '{' for loop closing bracket.");
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

  fseek(fp, 1 + size_of_repititions, SEEK_CUR);

  return 0;
}

int run(char command) {

  int value = 0;
  int num_in = 0;

  switch(command) {

    case PTR_LEFT:
      --ptr;
      break;

    case PTR_RIGHT:
      ++ptr;
      break;

    case PTR_INCREMENT:
      num_in = fscanf(fp, "%d", &value);
      if (num_in == 1) {
        (*ptr)+= value;
      } else {
        (*ptr)++;
      }
      break;

    case PTR_DECREMENT:
      num_in = fscanf(fp, "%d", &value);
      if (num_in == 1) {
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

    case FOR_LOOP_START:
      break;
    case FOR_LOOP_END:
      return for_loop();
      break;
    case EOF:
      return EOF;
  }

  return 0;
}

int main(int argc, char **argv) {

  ptr = mem;

  if (argc < 2) {
    printf("Specify a Brainfuck file to interpret.\n");
    return -1;
  }

  fp = fopen(argv[1], "r");
  if (!fp) {
    printf("Brainfuck file not found.\n");
    return -1;
  }

  int state = 0;

  while (state != EOF){
    state = run(fgetc(fp));
  }

  fclose(fp);
  fp = NULL;

  return 0;
}