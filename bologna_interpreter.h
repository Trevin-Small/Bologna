// Memory size of Brainfuck programs
#define MEM_SIZE 30000

// Vanilla Brainfucks commands
#define PTR_LEFT_SHIFT     '<'
#define PTR_RIGHT_SHIFT    '>'
#define INCREMENT          '+'
#define DECREMENT          '-'
#define CHAR_IN            ','
#define CHAR_OUT           '.'
#define BRN_FCK_LOOP_START '['
#define BRN_FCK_LOOP_END   ']'

// Extended commands
#define COMMENT            '"'
#define ZERO               '_'
#define ABSOLUTE_SHIFT     ':'
#define MULTIPLY           '*'
#define DIVIDE             '/'
#define PTR_VALUE          '#'
#define FOR_LOOP_START     '{'
#define FOR_LOOP_END       '}'
#define QUERY              '?'
#define LOGIC_START        '('
#define LOGIC_END          ')'
#define EXIT               '~'

int read_args(int*);
int for_loop();
int run(char);