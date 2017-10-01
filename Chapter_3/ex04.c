#include <stdio.h>
#include <string.h>
#define MAXINPUT 200  //maximum buffer size
void itoa(int n, char s[]);
void reverse(char s[]);

/* Exercise 3-4. In a two's complement number representation, our version of
  itoa does not handle the largest negative number, that is, the value of
  n equal to -(2wordsize-1). Explain why not. Modify it to print that value
  correctly, regardless of the machine on which it runs. */

/* The reason is because in twos compliment, instead of having two 0s there
  is only one, which is represented on the positive side of twos compliment,
  hence twos compliment maximum positive value is always equal to the maximum
  negative value -1 */

int main(void){
  char s[MAXINPUT];
  int n;
  scanf("%d", &n);
  itoa(n, s);
  printf("%s\n", s);

  return 0;
}

/* itoa: converts n to a string (int to string conversion) */
void itoa(int n, char s[]){
  int sign = (n < 0) ? -1 : 1; // record sign
  int i = 0; // string cursor

  do{
    s[i++] = sign * (n % 10) + '0';
  } while ((n /= 10) != 0);
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
