#include <stdio.h>

/*  Exercise 1-2. Experiment to find out what happens when prints's argument
    string contains \c, where c is some character not listed above.  */

main()
{
  printf("\c\n");
}

/* The above will compile but just print the character c
   The table below shows the escape character sequence

  Escape      Hex value   Character Represented
  sequence    in ASCII
    \a	         07	      Alert (Beep, Bell) (added in C89)[1]
    \b	         08	      Backspace
    \f	         0C	      Formfeed
    \n	         0A	      Newline (Line Feed); see notes below
    \r	         0D	      Carriage Return
    \t	         09	      Horizontal Tab
    \v	         0B	      Vertical Tab
    \\	         5C	      Backslash
    \'	         27	      Single quotation mark
    \"	         22	      Double quotation mark
    \?	         3F	      Question mark (used to avoid trigraphs)

    \nnn	       any	    The byte whose numerical value is given by nnn
                          interpreted as an octal number

    \xhh…	       any	    The byte whose numerical value is given by hh…
                          interpreted as a hexadecimal number

    \e	         1B	      escape character (some character sets)
    \Uhhhhhhhh	 none	    Unicode code point where h is a hexadecimal digit
    \uhhhh	     none	    Unicode code point below 10000 hexadecimal
*/
