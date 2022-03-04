# BrainFuck Extended
This project is (for fun!) completely useless. I took the existing BrainFuck programming language, and wrote a new interpreter in C, which adds lots of new commands, which can be seen below.
<br>
<br>
<br>
# Added Features

## SHORTHAND SYNTAX OF EXISTING (AND NEW) OPERATORS
```brainfuck
>>> == >3
++ == +2
---- == -4
<<<<< == <5
```

## ZERO
```_``` Sets the value of the current pointer to zero

## MULTIPLICATION
```*x``` Multiplies current pointer value by ```x``` 

## DIVISION
```/x``` Divides the current pointer value by ```x```

## CURRENT POINTER VALUE
```#``` Gets value of current pointer (will be treated as if an integer was in the code)  
```{}#``` A for loop that repeats as many times as the value of the current pointer
```+#``` Adds current pointer value to the current pointer value

## MEMORY INDEXING
```#x``` Every case from above applies, but rather than referencing the current pointer, it references pointer at memory index ```x```
```brainfuck
Remember: In BrainFuck, memory is an array
-----------------------------------------
#x Represents the value at memory index x

EX: #1 = mem[1] = some_value
-----------------------------------------


>#1 (Move pointer right #1 times)

<#15 (Move pointer left #15 times)

+#4 (Add #4 to the current pointer)

-#6 (Subtract #6 from the current pointer)

.#91 (Print current pointer #91 times)

#12. (Print the value of #12)

*#2 (Multiply current pointer value by #2)

/#8 (Divide current pointer value by #8)

{}#3 (For loop repeats #3 times)
```


## FOR LOOP
```{}x``` Repeats code inside the indices ```x``` times, or ```{}#5``` repeats as many times as the value at memory index 5.

<br>

# GOAL
Add a few more features to the language, then create tic tac toe with BrainFuck Extended.

<br>

# If anyone is interested in playing around with this language:

#### The interpreter for BrainFuck Extended is titled ```bf_extended.c```. You will need to download this file.

####  Compile this file with: ```gcc -o brainfuck bf_extended.c```

#### And run a BrainFuck file with ```./brainfuck your_brainfuck_file.bf```
