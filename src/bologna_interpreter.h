// Memory size of Brainfuck programs
#define MEM_SIZE 30000

// Standard Brainfuck commands
#define PTR_LEFT_SHIFT     '<'
#define PTR_RIGHT_SHIFT    '>'
#define INCREMENT          '+'
#define DECREMENT          '-'
#define CHAR_IN            ','
#define CHAR_OUT           '.'
#define BRN_FCK_LOOP_START '['
#define BRN_FCK_LOOP_END   ']'

// Bologna Commands
#define COMMENT            '"'
#define ZERO               '_'
#define ABSOLUTE_SHIFT     ':'
#define MULTIPLY           '*'
#define DIVIDE             '/'
#define PTR_VALUE          '#'
#define BRACE_START        '{'
#define BRACE_END          '}'
#define QUERY              '?'
#define LOGIC_START        '('
#define LOGIC_END          ')'
#define LESS_THAN          '<'
#define GREATER_THAN       '>'
#define EQUAL              '='
#define NOT                '!'
#define EXIT               '~'

void print_error();
int read_args(int *value);
int for_loop();
int query();
int run(char command);