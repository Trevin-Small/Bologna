"=============================
| Trevin Small | Spring 2022 |
==============================

NOTE;
===================================================================================================
Pointer starts at memory index 0 | In this example the pointer is never moved
All memory values are initially zero


PROGRAM EXECUTION;
===================================================================================================

1) '+72' Add character H (ascii value 72) to memory at the pointer index (which is 0)
2) '.' Print it out with
3) '_' Set the memory value back to zero (otherwise adding new characters would sum their values)
4) Repeat this for each character of 'HELLO WORLD'


CODE;
==================================================================================================="

+72._+69._+76._+76._+79._+32._+87._+79._+82._+76._+68._+10.

"EXPECTED OUTPUT:
==================================================================================================="
HELLO WORLD