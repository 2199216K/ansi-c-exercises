#include <stdio.h>
#define MAXLINE 1000  /* maximum input line length */

/*  Exercise 1-16. Revise the main routine of the longest-line program so it
    will correctly print the length of arbitrary long input lines, and as much
    as possible of the text. */

int getlinelength(char line[], int maxline);
void copy(char to[], char from[]);

/*print the longest input line */
int main()
{
  int len;                /* current line length */
  int max;                /* maximum line length seen so far */
  char line[MAXLINE];     /* current input line */
  char longest[MAXLINE];  /* longest line saved */

  max = 0;
  while ((len = getlinelength(line, MAXLINE)) > 0)
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  if (max > 0)    /* there was a line */
    printf("Longest line length: %d\n", max);
    printf("%s", longest);
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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
  ++i;
}
