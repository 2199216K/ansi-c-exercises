#include <stdio.h>

/*  Exercise 1-22. Write a program to ``fold'' long input lines into two or
    more shorter lines after the last non-blank character that occurs before
    the n-th column of input. Make sure your program does something intelligent
    with very long lines, and if there are no blanks or tabs before the
    specified column. */

#define MAXLINE 10  /* character limit per line */
#define TABSIZE 8   /* tab size in terms of spaces */

char line[MAXLINE]; /* buffer for PrintLine */

int TabToSpace(int index);  /* Formats tabs to spaces from index */
void PrintLine(int index);  /* Prints buffer until index */
int FindSpace(int index);   /* Finds space before index and returns its
                               position+1 */
int ResetIndex(int index);  /* Resets Index to the last character added to
                               line[]. if no chars found, returns 0 */

int main(){
  int c, index;   /* c: getchar character, index: array position */
  index = 0;

  while((c = getchar()) != EOF){
    line[index] = c;

    if (c == '\t'){
      index = TabToSpace(index);
    }
    else if (c == '\n'){
      PrintLine(index);
      index = 0;
    }
    else if (++index == MAXLINE){
      index = FindSpace(index);
      PrintLine(index);
      index = ResetIndex(index);
    }
  }
}

/* Formats tabs to spaces and returns index. On full lines calls PrintLine
   and returns index = 0 */
int TabToSpace(int index){
  line[index] = ' ';  /* replace tab with space */

  /* Until Tabstop or MAXLINE add spaces to buffer */
  for(++index; index < MAXLINE && index % TABSIZE != 0; ++index){
    line[index] = ' ';
  }

  if (index == MAXLINE){  /* line is full, needs folded */
    PrintLine(index);
    return 0;             /* reset index position */
  }
  return index; /* if line is not full return index position*/
}

/* Prints line up to(not including) specified index */
void PrintLine(int index){
  int j;

  for(j = 0; j < index; ++j){
    putchar(line[j]);
  }
  if (index == MAXLINE && line[j-1] != ' '){
    putchar('-');
  }
  if (index > 0){   /* if line is not empty add newline */
    putchar('\n');
  }
}

/* Finds space in line, and returns its index+1. If no space is found
   returns MAXLINE */
int FindSpace(int index){
  while(index > 0 && line[index] != ' '){ /* until space or start of line */
    --index;                              /* traverse backwards */
  }
  if (index > 0){                  /* if space is found, return index+1 */
    return index+1;
  }
  else{
    return MAXLINE;         /* no space was found so return MAXLINE */
  }
}

/* ResetIndex moves all remaining chars to the start of the array and returns
   the index position of the last char entered + 1 (next position) */
int ResetIndex(int index){
  int j,k;

  if (index == 0 || index == MAXLINE){
    return 0;             /* line was full or empty return index = 0 */
  }
  else{
    j = 0;  /* move remaining character to the start of the array */
    for (k = index; k < MAXLINE; ++k){
      line[j] = line[k];
      j++;
    }
    return j; /* return next available index */
  }
}
