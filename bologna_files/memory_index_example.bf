"=============================
| Trevin Small | Spring 2022 |
==============================

MEMORY OPERATOR SYNTAX:
===================================================================================================

'#' Operator -> Get byte value of pointer

'#x' Operator -> Get byte value at memory index 'x'


CHAINING OPERATORS:
============================
>#x -> Shift right '#x' times
<#x -> Shift left '#x' times
:#x -> Go to memory index '#x'

+#x -> Add '#x' to byte at pointer
-#x -> Subtract '#x' from byte at pointer
*#x -> Multiply '#x' to byte at pointer
/#x -> Divide byte at pointer by '#x'

{}#x -> Repeat loop '#x' times

?(#x<#y){} -> Compare values of '#x' and '#y'

SPECIAL CASE:
============================
.#x -> Prints the byte at the pointer '#x' times (The value of memory index x times)
#x. -> Prints the value of memory index x


CODE:
==================================================================================================="



"EXAMPLE 1:
================"

Add 10 to the byte at the pointer
+10

For loop repeats 10 times because the value of the byte at the pointer is 10
{ +10. }#


"EXAMPLE 2:
================"

Set index 5 to value 65
:5 +65

Move to index 0
:0

Print the value of index 5 with "#5" (Replaced by the value of mem index 5) and the print operator "."
#5.

