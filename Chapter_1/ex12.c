#include <stdio.h>

/* Exercise 1-12. Write a program that prints its input one word per line. */

int main()
{
  int c, nl;

  nl = 1;
  while((c = getchar()) != EOF){
    if(c != '\t' && c != '\n' && c != ' '){
      nl = 0;
      putchar(c);
    }
    else if(nl == 0){
      nl = 1;
      putchar('\n');
    }
  }
}
