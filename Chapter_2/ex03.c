#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAXLENGTH 8

/*  Exercise 2-3. Write a function htoi(s), which converts a string of
    hexadecimal digits (including an optional 0x or 0X) into its equivalent
    integer value. The allowable digits are 0 through 9, a through f, and
    A through F. */

int htoi(char s[]);

int main(){

  int c, i, result;
  char s[MAXLENGTH];

  i = 0;
  while ((c = getchar()) != EOF){
    if (i == MAXLENGTH-1 && c != '\n'){   // ensure correct input size
      printf("Error: Input exceeds MAXLENGTH(= %d)\n\n", MAXLENGTH);
      while((c = getchar()) != '\n')
        ;
      i = 0;
    }

    else if(c == '\n'){
      if((i == 2 && s[1] == 'X') || i == 0){ // ensure hex string is not empty
        printf("Error: Empty Hex String\n\n");
        i = 0;
      }
      else{
        s[i] = '\0';                      // add endpoint to hex string
        result = htoi(s);                 // convert to int
        printf ("The above hexadecimal to INT is equal to: %d\n\n", result);
        i = 0;
      }
    }

    else if (isdigit(c) || ((c = toupper(c)) >= 'A' && c <= 'F')){
      s[i] = c;  // add hex digits to array
      ++i;
    }

    else if(i == 1 && (c = toupper(c)) == 'X' && s[0] == '0'){ //allow 0x and 0X
      s[i] = c;
      ++i;
    }

    else{ // if invalid input is found
      printf("Error: Not a valid hexadecimal input\n\n");
      while((c = getchar()) != '\n')
        ;
      i = 0;
    }

  }
  return 0;
}

//converts hexadecimal to int
int htoi(char s[]){
  int i, result, x;
  result = 0;

  for (i = 0; s[i] != '\0'; ++i)
    ;   // find end of hexadecimal

  x = 0;
  for (--i; i >= 0 && s[i] != 'X'; --i){
    if(isdigit(s[i])){
      result += (int)pow(16,x) * (s[i] - '0');
    }
    else{
      result += (int)pow(16,x) * (s[i] - 'A' + 10);
    }
    ++x;
  }
  return result;
}
