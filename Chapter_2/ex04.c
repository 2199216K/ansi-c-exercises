#include <stdio.h>

#define MAXINPUT 100    // Maximum string input

/*  Exercise 2-4. Write an alternative version of squeeze(s1,s2) that deletes
    each character in s1 that matches any character in the string s2. */

void squeeze(char s1[], char s2[]);

int main(){
  char s[MAXINPUT];
  char blacklist[MAXINPUT];

  while(1){
    printf("Enter string to squeeze: ");
    if (fgets(s, sizeof(s), stdin) == NULL){
      putchar('\n');
      break;
    }

    printf("Enter character blacklist: ");
    if (fgets(blacklist, sizeof(blacklist), stdin) == NULL){
      putchar('\n');
      break;
    }

    squeeze(s,blacklist);

  }
  return 0;
}

// removes characters in s2 from s1 and prints s1
void squeeze(char s1[], char s2[]){
  int i, j, k;

  for (i = j = 0; s1[i] != '\0'; ++i){ // for each element in s1
    for (k = 0; s2[k] != '\0' && s1[i] != s2[k]; ++k){
      ; // iterate through s2 to see if its there
    }
    if (s2[k] == '\0'){
      s1[j++] = s1[i]; // if its not on s2 add it to s1 and increment j
    }
  }
  s1[j] = '\0';  // add endpoint to new s1

  printf("Squeezed string: %s\n\n", s1);

}
