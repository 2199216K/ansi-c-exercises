#include <stdio.h>

/*  Exercise 1-20. Write a program detab that replaces tabs in the input with
    the proper number of blanks to space to the next tab stop. Assume a fixed
    set of tab stops, say every n columns. Should n be a variable or a
    symbolic parameter? */

#define MAXLINE 1000     /* maximum line legnth */
#define TABSIZE 8        /* size of the tabs(in spaces) */

int getlinelength(char s[], int lim);

int main()
{
  char line[MAXLINE];
  int i, j, k, colnum;

  while (getlinelength(line, MAXLINE) > 0)  /* while line is not empty */
  {
    colnum = 0;
    for(i = 0; line[i] != '\0'; ++i){  /* iter. until end of line is reached */
      if (line[i] == '\t'){            /* if it contains a tab */
        j = TABSIZE - (colnum % TABSIZE);  /* set j to amount of spaces req.*/
        for (k = 0; k < j; ++k){       /* iter. until amount is satisfied */
          putchar(' ');               /* ASCII '0' = 48 (for testing purp.) */
          ++colnum;
        }
      }
      else{
        putchar(line[i]);              /*if no tab is found then output char */
        ++colnum;
      }
    }
  }

  return 0;
}

/* getlinelength: read a line into s, return length */
/* this function is from previous examples in the book */
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
