"=============================
| Trevin Small | Spring 2022 |
==============================

QUERY SYNTAX:
===================================================================================================

?(logical expression){code to be ran}

Given that the logical expression is true, the code inside the braces will be ran.
Otherwise, it will be skipped.


CODE:
==================================================================================================="

?(2=3){:2 _ +65.} "This statement is false. 'A' should not be printed."

?(1=1){:2 _ +66.} "This statement is true. 'B' should be printed."

?(2<3){:2 _ +67.} "This statement is true. 'C' should be printed."

?(2>3){:2 _ +68.} "This statement is false. 'D' should not be printed."

?(2!3){:2 _ +69.} "This statement is true. 'E' should be printed."


"Go to index 5, add 88"
:5 +88

"Go to index 6, add 89"
:6 +89

"Compare index 5 with index 6. The expression is true, so F will be printed."
?(#5<#6){ ?(#5<#6){:2 _ +70.} }

"Expected output:
==================================================================================================="
BCEF