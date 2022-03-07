gcc ./src/bologna_parser.c -o ./bologna_parser
gcc ./src/bologna_interpreter.c -o ./bologna_interpreter

touch temp.bf

./bologna_parser $1 temp.bf
./bologna_interpreter temp.bf

rm temp.bf
