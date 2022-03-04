# BrainFuck Extended
This project is (for fun!) completely useless. I took the existing BrainFuck programming language, and wrote a new interpreter in C, which adds lots of new commands, which can be seen below.
<br>
<br>

## SHORTHAND SYNTAX OF EXISTING (AND NEW) OPERATORS
```
>>> == >3
++ == +2
---- == -4
<<<<< == <5
```
## FOR LOOP
```{}x``` Repeats code inside the indices ```x``` times.  

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
```*#4``` Multiplies the current pointer value by the value at memory index 4
```#6.``` Print the value at memory index 6
