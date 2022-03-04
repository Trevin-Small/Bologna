# Brainfuck-Interpreter
A BrainFuck interpreter written in C

### interpreter.c
An interpreter for "vanilla" Brainfuck

## interpreter_extended.c
A spinoff of Brainfuck I made.

New Syntax:
```
//SHORTHAND SYNTAX 

>>> == >3
++ == +2
---- == -4
<<<<< == <5

// FOR LOOP

{<2+3}5

Repeats <2+3 five times 

// EXAMPLE CODE

{+32.-32+72.-72+69.-69+76.-76+76.-76+79.-79+32.-32+87.-87+79.-79+82.-82+76.-76+68.-68+10.-10}5

The above prints HELLO WORLD five times 
```
