#include <stdio.h>
#include <string.h>
#define MAXINPUT 200  //maximum buffer size
void itob(int n, char s[], int b);
void reverse(char s[]);

/* Exercise 3-5. Write the function itob(n,s,b) that converts the integer n
  into a base b character representation in the string s. In particular,
  itob(n,s,16) formats s as a hexadecimal integer in s. */

int main(void){
  char s[MAXINPUT];
  int n,b;
  printf("Enter the number to be converted: ");
  scanf("%d", &n);
  printf("\nEnter the base to convert to: ");
  scanf("%d", &b);
  itob(n, s, b);
  printf("\n%d has been converted to %s (base %d)\n", n, s, b);

  return 0;
}

/* itob: converts n to be represented in base b */
void itob(int n, char s[], int b){
  int sign = (n < 0) ? -1 : 1; // record sign
  int i = 0; // string cursor
  n = n * sign;
  do{
    s[i++] = ((n % b) > 9) ? ((n % b) + 'A' - 10) : ((n % b) + '0');
  } while ((n /= b) != 0);
  if (sign == -1)
    s[i++] = '-';
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
