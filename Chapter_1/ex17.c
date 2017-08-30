#include <stdio.h>
#define MAXLINE 1000  /* maximum input line length */
#define MINLENGTH 80  /* minimum line lenght to be printed */

/*  Exercise 1-17. Write a program to print all input lines that are longer
    than 80 characters. */

int getlinelength(char line[], int maxline);

/*print input lines that are at least 80 characters long */
int main()
{
  int len;                /* current line length */
  char line[MAXLINE];     /* current input line */

  while ((len = getlinelength(line, MAXLINE)) > 0)
    if (len >= 80)
      printf("%s", line);
  return 0;
}

/* getlinelength: read a line into s, return length */
int getlinelength(char s[], int lim)
{
  int c, i;
  for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n'){
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}
