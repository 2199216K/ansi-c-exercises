#include <stdio.h>

/*  Exercise 1-20. Write a program detab that replaces tabs in the input with
    the proper number of blanks to space to the next tab stop. Assume a fixed
    set of tab stops, say every n columns. Should n be a variable or a
    symbolic parameter? */

#define TABSIZE 8

int main()
{
  int c, i, colnum;
  colnum = 0;
  while ((c = getchar()) != EOF)
  {
    switch (c) {
      case '\n':
        colnum = 0;
        putchar(c);
        break;

      case '\t':
        for ( i = TABSIZE - colnum % TABSIZE, colnum += i; i > 0; --i)
          putchar(' ');     /* space is shown as star for testing purposes */
        break;

      default:
        ++colnum;
        putchar(c);
        break;
    }
  }
  return 0;
}
