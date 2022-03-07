if [ ! -f ./bologna_parser ]; then
gcc ./bologna_parser.c -o ./bologna_parser
fi

if [ ! -f ./bologna_interpreter ]; then
gcc ./bologna_interpreter.c -o ./bologna_interpreter
fi

touch .temp_bologna

./bologna_parser $1 .temp_bologna
./bologna_interpreter .temp_bologna

rm .temp_bologna
