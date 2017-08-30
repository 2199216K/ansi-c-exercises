#include <stdio.h>

/* Exercise 1-9. Write a program to copy its input to its output,
  replacing each string of one or more blanks by a single blank */

int main()
{
  int ch,lch; // variables to store character and last characters
  for (lch = 0; (ch = getchar()) != EOF; lch = ch){
    if(ch == ' ' && lch == ' ')
      ;
    else putchar(ch);
  }
}
