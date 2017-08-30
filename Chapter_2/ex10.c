#include <stdio.h>

/*  Exercise 2-10. Rewrite the function lower, which converts upper case letters
    to lower case, with a conditional expression instead of if-else. */

int lower(int c);

int main(){
  int c;

  printf("Enter characters to be converted to lowercase:\n");
  while ((c = getchar()) != EOF){
    putchar(lower(c));
  }
  return 0;
}

int lower(int c){

  return (c >= 'A' && c <= 'Z') ? 'a' + c - 'A' : c;

}
