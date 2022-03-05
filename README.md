# Bologna ![Bologna Logo](https://github.com/Trevin-Small/Bologna/bologna.png)
**Bologna is an esoteric interpreted programming language**
- Intended to be minimalistic yet (somewhat?) useable, Bologna is an un-intuitive, ridiculous language.

- As a derivative of the BrainFuck programming language, it retains the original 8 commands from BrainFuck (```+-<>[],.```)

## How does it compare to BrainFuck?
- Like BrainFuck, Bologna uses a single 30,000 Byte array for the entirety of the program.
- Memory is stored as signed 8-bit integers, unlike many implementations of BF which use unsigned characters.
- Memory indexing, for loops, and rudimentary logic are a few of Bologna's features.

# Cheat Sheet

| Pointer Movement |      |      |
|------------------|------|------|
| ```>x```               |      |      |
| ```<x```               |      |      |
| ```:x```            |      |      |
| **Value Operations** |      |      |
| ```_```               |      |      |
| ```+x```               |      |      |
| ```-x```               |      |      |
| ```*x```               |      |      |
| ```/x```               |      |      |
| **Loops**            |      |      |
| ```[ ]```              |      |      |
| ```{ }x```             |      |      |
| **Memory Indexing**  |      |      |
| ```#x```               |      |      |
|                  |      |      |
|                  |      |      |
|  **Other**                |      |      |
|   ```~```           |      |      |
|   ```"```           |      |      |
|            |      |      |


# Command Explanations

## SHORTHAND SYNTAX OF EXISTING (AND NEW) OPERATORS
```brainfuck
>>> == >3
++ == +2
---- == -4
<<<<< == <5
```

# Pointer Movement

## LEFT SHIFT

## RIGHT SHIFT

# ABSOLUTE SHIFT

# Numerical Operators

## ZERO
```_``` Sets the value of the current pointer to zero

## ABSOLUTE SHIFT
```:x``` Shifts the pointer to index ```x```.

## MULTIPLICATION
```*x``` Multiplies current pointer value by ```x``` 

## DIVISION
```/x``` Divides the current pointer value by ```x```

# Loops

## FOR LOOP
```{}x``` Repeats code inside the indices ```x``` times, or ```{}#5``` repeats as many times as the value at memory index 5.

# MEMORY INDEXING

## CURRENT INDEX OPERATOR
```#``` Gets value of current pointer (will be treated as if an integer was in the code)
```{}#``` A for loop that repeats as many times as the value of the current pointer
```+#``` Adds current pointer value to the current pointer value

## MEMORY INDEX OPERATOR
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

# TODO
- Add support for nested for loops (They currently dont work in the slightest LOL)
- Add ```?{}``` Operator which checks if a value is greater than zero and runs the code inside the braces if so.

<br>

# If anyone is interested in playing around with this language:

#### The interpreter for BrainFuck Extended is titled ```bf_extended.c```. You will need to download this file.

####  Compile this file with: ```gcc -o brainfuck bf_extended.c```

#### And run a BrainFuck file with ```./brainfuck your_brainfuck_file.bf```

# Examples
- Inside of the ```/bologna``` folder, there are ```.bf (brainfuck)``` files. 
- 