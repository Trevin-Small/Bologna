#include <stdio.h>

// Memory size of Brainfuck programs
#define MEM_SIZE 30000

// All of Brainfucks commands.... only 8 lines LOL
#define PTR_LEFT '<'
#define PTR_RIGHT '>'
#define PTR_INCREMENT '+'
#define PTR_DECREMENT '-'
#define CHAR_IN ','
#define CHAR_OUT '.'
#define LOOP_START '['
#define LOOP_END ']'

char mem[MEM_SIZE] = {0};
FILE * fp;
char * ptr;

int run() {

  int value = 0;
  int num_in = 0;

  switch(fgetc(fp)) {

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

    case LOOP_START:
      if (*ptr == 0) {
        int start_counter = 0;
        do {
          char start_in = fgetc(fp);
          if (start_in == LOOP_START) {
            start_counter++;
          } else if ((start_in == LOOP_END) && (start_counter > 0)) {
            start_counter--;
          } else if ((start_in == LOOP_END) && (start_counter == 0)) {
            fseek(fp, 1, SEEK_CUR);
            break;
          }
        } while(1 == 1);
      }
      break;

    case LOOP_END:
      if (*ptr != 0) {
        int close_counter = 0;
        do {
          fseek(fp, -2, SEEK_CUR);
          char end_in = fgetc(fp);
          if (end_in == LOOP_END) {
            close_counter++;
          } else if ((end_in == LOOP_START) && (close_counter > 0)) {
            close_counter--;
          } else if ((end_in == LOOP_START) && (close_counter == 0)) {
            break;
          }
        } while(1 == 1);
          fseek(fp, -1, SEEK_CUR);
      }
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

  while (run() != EOF){continue;};
  printf("\n");
  fclose(fp);
  fp = NULL;

  return 0;
}