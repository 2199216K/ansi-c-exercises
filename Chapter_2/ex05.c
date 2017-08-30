#include <stdio.h>
#include <string.h>

#define MAXINPUT 100    // Maximum string input

/*  EExercise 2-5. Write the function any(s1,s2), which returns the first
    location in a string s1 where any character from the string s2 occurs, or -1
    if s1 contains no characters from s2. (The standard library function strpbrk
    does the same job but returns a pointer to the location.) . */

int any(char s1[], char s2[]);

int main(){
  char s[MAXINPUT];
  char key[MAXINPUT];
  int i;

  while(1){
    printf("Enter string to search: ");
    if (fgets(s, sizeof(s), stdin) == NULL){
      putchar('\n');
      break;
    }

    printf("Enter key: ");
    if (fgets(key, sizeof(key), stdin) == NULL){
      putchar('\n');
      break;
    }

    s[strlen(s)-1] = '\0';        // remove newlines from input
    key[strlen(key)-1] = '\0';    // remove newlines from input

    if((i = any(s,key)) != -1){
      printf("Found \"");
      putchar(s[i]);
      printf("\" at s1[%d]\n\n", i);
    }
    else{
      printf("No matches\n\n");
    }

  }
  return 0;
}

/*  returns the first location in a string s1 where any character from the
    string s2 occurs, or -1 if s1 contains no characters from s2 */
int any(char s1[], char s2[]){
  int i, j;

  for (i = 0; s1[i] != '\0'; ++i){
    for (j = 0; s2[j] != '\0'; ++j){
      if (s1[i] == s2[j]){            // if characters match
        return i;                     // return index of s1 where match occured
      }
    }
  }
  return -1;                          // else return -1 (no match)
}
