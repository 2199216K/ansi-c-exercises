#include <stdio.h>

/*  Exercise 1-14. Write a program to print a histogram of the frequencies of
    different characters in its input.  */

#define NOOFASCII 128 /* Total number of ASCII Characters */
int main()
{
  int c, i, j;
  int character[NOOFASCII];

  for(i = 0; i < NOOFASCII; ++i){
    character[i] = 0;
  }

  while ((c = getchar()) != EOF){
    ++character[c];
  }

  for (i = 32; i < NOOFASCII; ++i){
    putchar(i);

    for(j = 0; j < character[i]; ++j){
      putchar('*');
    }
    putchar('\n');
  }
}
