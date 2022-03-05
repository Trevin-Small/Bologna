![Bologna Logo](https://github.com/Trevin-Small/Bologna/blob/main/images/bologna.png)
## Bologna is an esoteric interpreted programming language
- Intended to be minimalistic yet (somewhat?) useable, Bologna is an un-intuitive, ridiculous language.

- Bologna is a derivative of the BrainFuck programming language, and retains the original 8 commands from BrainFuck (Those being: ```+-<>[],.```)

# Bologna Paradigm
### The name "Bologna" was chosen because this language is similar to the food;
That is, somewhat gross, and probably not your first choice.
- Bologna was made to see what could be acheived with a *very* simple language.
#### Basics
- **No conventional variables.** All values are stored at some index in the 30,000 signed 8-bit integer array
- **No functions**
- **No data types**, as *everything* is stored as an _int_8t
- **Interpreted** from your file *directly at runtime*
- **So dumb its cool**

# Cheat Sheet

| Pointer Movement      |      |
|-----------------------|------|
| ```>x```              |Shift pointer right ```x``` times   |
| ```<x```              |Shift pointer left ```x``` times   |
| ```:x```              |Move pointer to memory index ```x```  |
| **Value Operations**  |      |
| ```_```               |Set the byte at the pointer to zero  |
| ```+x```              |Add ```x``` to the byte at the pointer value   |
| ```-x```              |Subtract ```x``` from the byte at the pointer  |
| ```*x```              |Multiplty the byte at the pointer by ```x```   |
| ```/x```              |Divide the byte at the pointer by ```x```   |
| **Loops**             |      |
| ```[```               |If the byte at the pointer is zero, jump past matching ```]```      |
| ```]```               |If the byte at the pointer is non-zero, jump back to command after matching ```[``` |
| ```{ }x```            |Repeat code inside the braces ```x``` times   |
| **Memory Indexing**   |      |
| ```#```               |Get the value of the pointer's byte      |
| ```#x```              |Get value of the byte at index  ```x```      |
| **Query Operator**    |     |
| ```?(x<y){}```        |If the ```(boolean statement)``` is true, run the code inside the ```{}``` braces     |
| *Logical Operators*     |  Note: Can only be used inside of the '( )' of a Query    |
| ```>```               |Greater than  |
| ```<```               |Less than  |
| ```=```               |Equal to |
| ```!```               |Not equal to  |
|  **Other**            |      |
| ```~```               |End program execution  |
| ```"comments"```      |Comment (By default text is ignored, but comments ignore commands)<br> Ex: "+-.<>" will not execute any of the operators)|
|                       |      |

# Command Explanations

## SHORTHAND SYNTAX OF EXISTING (AND NEW) OPERATORS
```brainfuck
>>> == >3
++ == +2
---- == -4
<<<<< == <5
```

# POINTER MANIPULATION
Initially, the program pointer points to the beginning of the memory array at index 0.
## Left Shift
```<x``` Shifts the pointer to the left ```x``` number of times.

## Right Shift
```>x``` Shifts the pointer to the right ```x``` number of times

## Absolute Shift
```:x``` Shifts the pointer to memory index ```x```, regardless of its current position.

# Numerical Operators

## Zero
```_``` Sets the value of the current pointer to zero

## Multiplication
```*x``` Multiplies current pointer value by ```x```

## Division
```/x``` Divides the current pointer value by ```x```

# LOOPS

## "While" Loop
```[ ]``` BrainFuck's original loop implementation.

## For Loop
```{}x``` Repeats code inside the indices ```x``` times, or ```{}#5``` repeats as many times as the value at memory index 5.
Note that nested loops are not yet supported.

# MEMORY INDEXING

## Current Byte Operator
```#``` Gets value of current pointer (will be treated as if an integer was in the code)
```{}#``` A for loop that repeats as many times as the value of the current pointer
```+#``` Adds current pointer value to the current pointer value

## Byte at Index Operator
```#x``` Every case from above applies, but rather than referencing the current pointer, it references pointer at memory index ```x```
```brainfuck
Memory is an array of signed 8-bit integers
-------------------------------------------
#x Represents the value at memory index x

EX: #1 = mem[1] = some_value
-------------------------------------------


>#1 (Move pointer right #1 times)

<#15 (Move pointer left #15 times)

+#4 (Add #4 to the current pointer)

-#6 (Subtract #6 from the current pointer)

.#91 (Print current pointer #91 times)

#12. (Print the value of #12)

:#7 (Move pointer to index matching the value at memory index 7)

*#2 (Multiply current pointer value by #2)

/#8 (Divide current pointer value by #8)

{}#3 (For loop repeats #3 times)
```

# QUERY OPERATOR
## Query
```?(){}``` The query operator evaluates the expression inside of the parentheses, and only executes the code inside of the braces **if** the expression evaluates to true.
- Note that whitespace inside of '()' or between '?, (), {}' is not allowed.
- Example: ```?(a < b){+}``` is not permitted due to whitespace inside the logical expression
- ```? (a<b) {+}``` is also not permitted due to whitespace between the ```? (``` and ```) {```

```brainfuck
CODE
====================================

"Set mem[0] to 65 (ASCII A)"
:0 +65

"Set mem[1] to 10"
:1 +10

"Set mem[2] to 10"
:2 +10


"If ('10'='10')then{.}"
?(#1=#2){.}

EXPECTED OUTPUT
====================================
A
```
## Logical operators
- ```<``` Less than operator
- ```>``` Greater than operator
- ```=``` Equal to operator
- ```!``` Not equal operator

```brainfuck
?(10<11){+} "This is true, the '+' will be executed"

?(10>11){+} "This is false, the '+' will not be executed"

?(10=11){+} "This is false, the '+' will not be executed"

?(10!11){+} "This is true, the '+' will be executed"

```


# TODO
- Add Nested for loop support ```{ { }y }x```  (They currently dont work at all...)
- Create intermediary step before interpretation which optimizes the file for interpretation - removes all characters which are not commands.
- Fix while loop ```[ ]``` bug - currently, while loops will fail to exit under certain conditions.

<br>

# Using Bologna:
- First, clone the repo **OR** download the ```.c``` files in ```/src```
####  Compile the Bologna interpreter with:
```
gcc -o bologna bologna_interpreter.c
```

#### And run a Bologna file with
```
./bologna your_file.bf
```

# Bologna Example Code
- Inside of the ```/bologna_files``` folder, there are ```.bf (brainfuck)``` files.

### Hello World Example
```
hello_world.bf
```
```brainfuck
+72._+69._+76._+76._+79._+32._+87._+79._+82._+76._+68._+10.

"EXPECTED OUTPUT:
==========================================================="
HELLO WORLD
```
### Counter Example
An example of a for loop that counts from 0 to 9
```
counter_example.bf
```
```brainfuck
"Go to memory index 3, then add 10"
:3 +10

"Go to memory index 0, then add 48 (ASCII '0' character)"
:0 +48

"Print value and increment byte by one. Repeat '#3' times, which evaluates to 10 repitions."
{.+}#3

"Zero the index, add 10 (ASCII linebreak), and print it out"
_ +10 .

"Expected Output:
========================================================================================="
0123456789
```

### Tic Tac Toe
(Unfinished) Tic Tac Toe example written in Bologna
```
tic_tac_toe.bf
```
```brainfuck
FULL TIC TAC TOE AVAILABLE IN /bologna_files


"EXAMPLE (PORTION) OF CODE: 
===================================================================================="

"Print: Pick a cell 1 - 9) "

+80. _ +105. _ +99. _ +107. _ +32. _ +97. _ +32. _ +67. _ +101. _
+108. _ +108. _ +32. _ +49. _ +32. _ +45. _ +32. _ +57. _ +41. _ #11.

"Take a character input and store in memory index 50"
:50 _ ,

"Move to the index of the character the user specified. Write an 'O' in the cell"
:#50 _ +#13 :0 #10.


"EXAMPLE OUPUT:
===================================================================================="
-------
|X|O|X|
-------
|O|5|6|
-------
|7|8|9|
-------


Player 1 - Pick a Cell 1 - 9) 5


-------
|X|O|X|
-------
|O|X|6|
-------
|7|8|9|
-------

```