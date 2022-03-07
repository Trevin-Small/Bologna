if [ ! -f ./bologna_parser ]; then
gcc ./bologna_parser.c -o ./bologna_parser
fi

if [ ! -f ./bologna_interpreter ]; then
gcc ./bologna_interpreter.c -o ./bologna_interpreter
fi

touch .parsed_bologna

./bologna_parser $1 .parsed_bologna
./bologna_interpreter .parsed_bologna

rm .parsed_bologna