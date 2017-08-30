#include <stdio.h>
#define MAXLINE 1000  /* maximum input line length */

/*  Exercise 1-18. Write a program to remove trailing blanks and tabs from
    each line of input, and to delete entirely blank lines. */

int mgetline(char line[], int lim);
int removetrail(char rline[]);

/*print input lines that are at least 80 characters long */
int main(void)
{
  int len;                /* current line length */
  char line[MAXLINE];     /* current input line */

  while ((len = mgetline(line, MAXLINE)) > 0)
    if(removetrail(line) > 0)
      printf("%s", line);

  return 0;
}

/* mgetline: read a line into s, return length */
int mgetline(char s[], int lim)
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

/* removetrail: removes trailing blanks and tabs */
int removetrail(char s[])
{
  int i;

  for(i = 0; s[i] != '\n'; ++i)
    ;
  --i;

  for(i > 0; ((s[i] == ' ') || (s[i] == '\t')); --i)
    ; /* removing the trailing blanks and spaces */

  if(i >= 0)  /* non empty line */
  {
    ++i;
    s[i] = '\n';
    ++i;
    s[i] = '\0';
  }
  return i;
}
