#include <stdio.h>
#include <ctype.h>
#define MAXLINE 100

int mygetline(char line[], int max);
double atof(char s[]);


/* rudimentary calculator */
int main(){
  char line[MAXLINE];
  double sum;
  sum = 0;
  while (mygetline(line,MAXLINE) > 0)
    printf("\t%g\n", sum += atof(line));
  return 0;
}

// mygetline: get line into s return length
int mygetline(char s[], int lim){
  int c, i;

  i = 0;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    s[i++] = c;
  if (c == '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}

/* atof: convert stirng s to double */
double atof(char s[]){
  double val, power;
  int i, sign, esign, e;

  for (i = 0; isspace(s[i]); i++) // skip whitespace
    ;
  sign = (s[i] == '-') ? -1 : 1;  // save sign
  if (s[i] == '+' || s[i] == '-') // skip sign
    i++;
  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');  // add numbers starting from leftmost
  if (s[i] == '.')  // skip decimal if present
    i++;
  for (power = 1.0; isdigit(s[i]); i++){ //iterate until no digits found
    val = 10.0 * val + (s[i] - '0');  // add numbers after decimal
    power *= 10;  // incrementing a power to store how many numbers after '.'
  }
  if (tolower(s[i]) == 'e'){  // if exponential
    esign = s[++i] == '-' ? -1 : 1; // store exponent sign and
    if (s[i] == '-' || s[i] == '+') // skip if + or -
      ++i;
    for (e = 0; isdigit(s[i]); i++) // until no digits
      e = e * 10 + (s[i] - '0');  // store exponent
    if (esign < 0)  // if sign was negative increase power value
      for (i = 0; i < e; i++)
        power *= 10.0;
    else  // else decrease the power value
      for (i = 0; i < e; i++)
        power /= 10.0;
  }
  return sign * val / power;
}
