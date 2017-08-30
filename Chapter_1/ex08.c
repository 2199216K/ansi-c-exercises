#include <stdio.h>

/* Exercise 1-8. Write a program to count blanks, tabs, and newlines. */

/* count new lines, blanks and tabs in input */
int main()
{
  int c;
  int newlines;
  int tabs;
  int spaces;

  newlines = 0;
  tabs = 0;
  spaces = 0;
  while ((c = getchar()) != EOF){
    if (c == '\n'){
      ++newlines;
    }
    if (c == '\t'){
      ++tabs;
    }
    if (c == ' '){
      ++spaces;
    }
  }
  printf("newlines: %d\ntabs: %d\nspaces: %d\n", newlines, tabs, spaces);
}
