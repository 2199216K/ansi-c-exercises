#include <stdio.h>

/*  Exercise 1-21. Write a program entab that replaces strings of blanks by
    the minimum number of tabs and blanks to achieve the same spacing. Use the
    same tab stops as for detab. When either a tab or a single blank would
    suffice to reach a tab stop, which should be given preference? */

#define TABSIZE 8     /* the size of a tab in spaces */

int main()
{
    int c;            /* c: cursor */
    int spaces;       /* spaces: total space equivalent */
    int tsOffset;     /* tsOffset: distance to next Tabstop. */
    int colNum;       /* colNum: Column Counter */
    spaces = colNum = 0;       /* SOF, so no spaces or column traversal */

    while ((c = getchar()) != EOF){
      if (c == ' '){
        ++spaces;
      }
      else if (c == '\t'){  /* if tab, add appropriate spaces */
        spaces = spaces + TABSIZE - (colNum + spaces) % TABSIZE;
      }
      else{
        while(spaces){        /* if there are spaces to be placed */
          tsOffset = TABSIZE - colNum % TABSIZE; /* get tabstop offset */
          if (tsOffset <= spaces && tsOffset != 1){
            colNum += tsOffset;     /* adjust colNum to Tabstop */
            putchar('\t');
            spaces -= tsOffset;
          }
          else{
            while (spaces){
              putchar(' ');
              ++colNum;
              --spaces;

            }
          }
        }
        /* if there are no spaces to be placed */
        putchar(c);
        ++colNum;
        if (c == '\n'){     /* newline, so reset column counter */
          colNum = 0;
        }
      }
    }

    return 0;
}
