#include <stdio.h>
#include <ctype.h>
#define MAXINPUT 200 // maximum buffer size

/*  Exercise 3-3. Write a function expand(s1,s2) that expands shorthand
 notations like a-z in the string s1 into the equivalent complete list abc...xyz
 in s2. Allow for letters of either case and digits, and be prepared to handle
 cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is
 taken literally.
*/

void expand(char s1[], char s2[]);

int main(void){
  char s1[MAXINPUT], s2[MAXINPUT];
  int c;
  int i = 0;

  while ((c = getchar()) != '\n' && c < MAXINPUT){
    s1[i++] = c;
  }
  s1[i] = '\0';
  expand(s1,s2);
  printf("%s was converted to:\n%s\n",s1,s2);


  return 0;
}
/* Expands shorthand notations to include all characters in between
  eg. A-D --> ABCD */
void expand(char s1[], char s2[]){
  int i,j,k;

  for (i = j = 0; s1[i] != 0;){
    if(isalnum(s1[i]) && s1[i+1] == '-' && isalnum(s1[i+2])){

      if ((islower(s1[i]) && islower(s1[i+2])
        || isupper(s1[i]) && isupper(s1[i+2])
        || isdigit(s1[i]) && isdigit(s1[i+2]))
        && s1[i] < s1[i+2]){
        for (k = s1[i]; k < s1[i+2]; k++){
          s2[j++] = k;
        }
        i += 2;
      }
      else{
        s2[j++] = s1[i++];
        s2[j++] = s1[i++];
      }
    }

    else{
      s2[j++] = s1[i++];
    }
  }
  s2[j] = '\0';
}
