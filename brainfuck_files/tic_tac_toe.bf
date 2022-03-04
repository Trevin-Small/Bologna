_____________________________________________
|  Trevin S   ||  Spring     ||  2022       |
|_____________||_____________||_____________|
|  Tic        ||  Tac        ||  Toe        |
|_____________||_____________||_____________|
|  BrainFuck  ||  Extended   ||  Edition    |
|_____________||_____________||_____________|

================================================================

Note; Leave 0 Empty! This is the default memory block we use to print.

Initialize Index memory 1_9 to ' ' (Space)
To hold the vals of (X | O) cells in the game

{ #10+ >+#10 +48 .}9 <9

Initialize Index 10 to \n (linebreak)
>10 _ +10<10
#10.

Initialize Index 11 to ' ' (Space)
>11 _ +32<11

Initialize Index 12 to '|'
>12+124<12

Initialize Index 13 to 'X'
>13+88<13

Initialize Index 14 to 'O'
>14+79<14


Start Game Loop
================================================================
{


  Print the gameboard
  ================================================================

  Print a row of hyphens
  _ +45 .7 -45 #10.


  Print top row | mem|1| | mem|2| | mem|3| |
  _ #12. #1. #12. #2. #12. #3. #12. #10.


  Print a row of hyphens
  _ +45 .7 -45 #10.


  Print middle row | mem|4| | mem|5| | mem|6| |
  _ #12. #4. #12. #5. #12. #6. #12. #10.


  Print a row of hyphens
  _ +45 .7 -45 #10.


  Print bottom row | mem|7| | mem|8| | mem|9| |
  _ #12. #7. #12. #8. #12. #9. #12. #10.


  Print a row of hyphens
  _ +45 .7 -45 #10.

  End Gameboard Print
  ================================================================


  Player 1 Input;
  ================================================================

  #10. #10.

  Print "Player 1) "

  _ +80. _ +108. _ +97. _ +121. _ +101. _ +114. _ +32. _ +49. _ +41. _ #11.

  Print "Pick a cell 1 _ 9;"

  +80. _ +105. _ +99. _ +107. _ +32. _ +97. _ +32. _ +67. _ +101. _ +108. _ +108. _ +32. _ +49. _ +32. _ +45. _ +32. _ +57. #10.

  Character input
  <1000 >50 , <1000 >#50 +#13 <1000 #10.

  #10.

  End Player 1 Input
  ================================================================


   Print the gameboard
  ================================================================

  Print a row of hyphens
  _ +45 .7 -45 #10.


  Print top row | mem|1| | mem|2| | mem|3| |
  _ #12. #1. #12. #2. #12. #3. #12. #10.


  Print a row of hyphens
  _ +45 .7 -45 #10.


  Print middle row | mem|4| | mem|5| | mem|6| |
  _ #12. #4. #12. #5. #12. #6. #12. #10.


  Print a row of hyphens
  _ +45 .7 -45 #10.


  Print bottom row | mem|7| | mem|8| | mem|9| |
  _ #12. #7. #12. #8. #12. #9. #12. #10.


  Print a row of hyphens
  _ +45 .7 -45 #10.

  End Gameboard Print
  ================================================================


  Player 2 Input
  ================================================================

  #10. #10.

  Print "Player 2) "

  _ +80. _ +108. _ +97. _ +121. _ +101. _ +114. _ +32. _ +50. _ +41. _ #11.

  Print "Pick a cell 1 _ 9;"

  +80. _ +105. _ +99. _ +107. _ +32. _ +97. _ +32. _ +67. _ +101. _ +108. _ +108. _ +32. _ +49. _ +32. _ +45. _ +32. _ +57. #10.

  Character input
  <1000 >50 , <1000 >#50 +#14 <1000 #10.

  #10.

  End Player 2 Input
  ================================================================


   End Game Loop
}4 ================================================================


Print the gameboard
================================================================

Print a row of hyphens
_ +45 .7 -45 #10.


Print top row | mem|1| | mem|2| | mem|3| |
_ #12. #1. #12. #2. #12. #3. #12. #10.


Print a row of hyphens
_ +45 .7 -45 #10.


Print middle row | mem|4| | mem|5| | mem|6| |
_ #12. #4. #12. #5. #12. #6. #12. #10.


Print a row of hyphens
_ +45 .7 -45 #10.


Print bottom row | mem|7| | mem|8| | mem|9| |
_ #12. #7. #12. #8. #12. #9. #12. #10.


Print a row of hyphens
_ +45 .7 -45 #10.

End Gameboard Print
================================================================


Player 1 Final Turn
================================================================


Player 1 Input;
================================================================

#10.

Print "Player 1) "
#10. _ +80. _ +108. _ +97. _ +121. _ +101. _ +114. _ +32. _ +49. _ +41. _ #11.

Print "Pick a cell 1 _ 9;"
+80. _ +105. _ +99. _ +107. _ +32. _ +97. _ +32. _ +67. _ +101. _ +108. _ +108. _ +32. _ +49. _ +32. _ +45. _ +32. _ +57. #10.

Character input
<1000 >50 , <1000 >#50 +#13 <1000 #10.

End Player 1 Input
================================================================


Print the gameboard
================================================================

Print a row of hyphens
_ +45 .7 -45 #10.


Print top row | mem|1| | mem|2| | mem|3| |
_ #12. #1. #12. #2. #12. #3. #12. #10.


Print a row of hyphens
_ +45 .7 -45 #10.


Print middle row | mem|4| | mem|5| | mem|6| |
_ #12. #4. #12. #5. #12. #6. #12. #10.


Print a row of hyphens
_ +45 .7 -45 #10.


Print bottom row | mem|7| | mem|8| | mem|9| |
_ #12. #7. #12. #8. #12. #9. #12. #10.


Print a row of hyphens
_ +45 .7 -45 #10.

End Gameboard Print
================================================================


Game Finish
================================================================
