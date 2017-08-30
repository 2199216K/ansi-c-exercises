#include <stdio.h>
#define MAXLINE 1000  /* maximum input line length */

/*  Exercise 2-2. Write a loop equivalent to the for loop above without using
    && or ||. */

// Using solution from Exercise 1-16

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
// v v v v v v v v v v MODIFIED SECTION v v v v v v v v v v
  i = 0;    // start from first character
  while (i < lim-1){    // while i is within buffer size
    if((c = getchar()) == EOF){   // check if EOF
      break;
    }
    else if(c == '\n'){            // check if newline
      break;
    }
    else{
      s[i] = c;                   // add c to current array index
      ++i;                        // increment index
    }
  }
// ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ MODIFIED SECTION ^ ^ ^ ^ ^ ^ ^ ^ ^ ^
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
