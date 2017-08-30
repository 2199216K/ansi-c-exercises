#include <stdio.h>

/*  Exercise 1-13. Write a program to print a histogram of the lengths of words
    in its input. It is easyto draw the histogram with the bars horizontal; a
    vertical orientation is more challenging. */

#define   IN    1 /* inside a word */
#define   OUT   0 /* outside a word */

/* Histogram with word lengths */

int main()
{
  int c, i, j, state;
  int wlen[30];

  state = OUT;
  for (i = 0; i < 30; ++i)
    wlen[i] = 0;
  i = 0;

  while((c = getchar()) != EOF){
    if(c == ' ' || c == '\n' || c == '\t'){
      if(state == IN){
        ++i;
        state = OUT;
      }
    }
    else{
      ++wlen[i];
      state = IN;
    }
  }
  if (i != 0 && wlen[i] == 0)
    --i;

  for (i = 0; 0 < wlen[i] && i < 30; ++i){
    j = 0;
    while(j < wlen[i]){
      printf("*");
      ++j;
    }
    printf("\n");
  }
  printf("\nwords: %d\n", i);
}
