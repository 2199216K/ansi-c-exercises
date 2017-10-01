#include <stdio.h>
#include <string.h>
#define MAXINPUT 200  //maximum buffer size
void itoa(int n, char s[], int w);
void reverse(char s[]);

/* Exercise 3-6. Write a version of itoa that accepts three arguments instead
  of two. The third argument is a minimum field width; the converted number
  must be padded with blanks on the left if necessary to make it wide enough. */

int main(void){
  char s[MAXINPUT];
  int n, w;
  printf("Enter the number to be converted: ");
  scanf("%d", &n);
  printf("\nEnter the minimum width of the output: ");
  scanf("%d", &w);
  itoa(n, s, w);
  printf("%s\n", s);

  return 0;
}

/* itoa: converts n to a string (int to string conversion) */
void itoa(int n, char s[], int w){
  int sign = (n < 0) ? -1 : 1; // record sign
  int i = 0; // string cursor

  do{
    s[i++] = sign * (n % 10) + '0';
  } while ((n /= 10) != 0);
  if (sign == -1)
    s[i++] = '-';
  while (i < w){
    s[i++] = ' ';
  }
  s[i] = '\0';
  reverse(s);
}

/* reverse: reverses the input string */
void reverse(char s[]){
  int tmp, i, j;

  for (i = 0, j = strlen(s)-1; i < j; i++, j--){
    tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
  }
}
