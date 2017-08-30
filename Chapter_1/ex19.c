#include <stdio.h>
#define MAXLINE 1000 /* maximum input length */

/*  Exercise 1-19. Write a function reverse(s) that reverses the character
    string s. Use it to write a program that reverses its input a line at a
    time. */

int mgetline(char line[], int lim);
void reverseline(char line[]);

/* reverse and print input line */
int main()
{
  int len;                /* current line length */
  char line[MAXLINE];     /* current input line */

  while ((len = mgetline(line, MAXLINE)) > 0){
    reverseline(line);
    printf("%s\n", line);
  }
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

/* reverseline: reverses a character array */
void reverseline(char s[])
{
  int i, j;
  char tmp;

  i = 0;
  while (s[i] != '\n')
    ++i;

  j = i - 1;
  for (i = 0; i < j; ++i){
    // printf("i:%d and j:%d swapped\n",i,j);
    tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
    --j;
  }
}
