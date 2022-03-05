"=============================
| Trevin Small | Spring 2022 |
==============================


FOR LOOP SYNTAX:
===================================================================================================

{code to be repeated}x

Code inside the braces is what you desire to be repeated.

x is an integer argument (either hardcoded, or dynamic through '#x') which represents the number of iterations


CODE:
==================================================================================================="

"Go to memory index 3, then add 10"
:3 +10

"Go to memory index 0, then add 48 (ASCII '0' character)"
:0 +48

"Print the value and increment it by one. Repeat '#3' times, which evaluates to 10 repitions."
{.+}#3

"Zero the index, add 10 (ASCII linebreak), and print it out"
_ +10 .

"Expected Output:
==================================================================================================="
0123456789