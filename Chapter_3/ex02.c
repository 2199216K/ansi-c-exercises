#include <stdio.h>

#define MAXINPUT 1000   // maximum char array size

/*  Exercise 3-2. Write a function escape(s,t) that converts characters like
    newline and tab into visible escape sequences like \n and \t as it copies
    the string t to s. Use a switch. Write a function for the other direction
    as well, converting escape sequences into the real characters. */

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main(void){
  char s[MAXINPUT], t[MAXINPUT];
  int c;
  int i = 0;

  while ((c = getchar())!= EOF && i < MAXINPUT){
    t[i++] = c;
  }
  t[i] = '\0';
  escape(s, t);
  printf("\nInput converted to visible escape sequences:\n%s\n\n", s);
  unescape(s, t);
  printf("Input converted to string literals:\n%s\n", s);

  return 0;
}

/*  escape: convert newline and tab from t[] to visible escape sequences and
    copy string to s[] */
void escape(char s[], char t[]){
  int i,j;
  for (i = j = 0; t[i] != '\0'; ++i){
    switch (t[i]) {
      case '\n':
        s[j++] = '\\';
        s[j++] = 'n';
        break;
      case '\t':
        s[j++] = '\\';
        s[j++] = 't';
        break;
      default:
        s[j++] = t[i];
        break;
    }
  }
  s[j] = '\0';
}

/*  unescape: convert \n and \n from t[] to newline and tab and copy string
    to s[] */
void unescape(char s[], char t[]){
  int i,j;
  for (i = j = 0; t[i] != '\0'; ++i){
    if (t[i] != '\\'){
      s[j++] = t[i];
    }
    else{
      switch (t[++i]) {
        case 'n':
          s[j++] = '\n';
          break;
        case 't':
          s[j++] = '\t';
          break;
        default:
          s[j++] = '\\';
          s[j++] = t[i];
          break;
      }
    }
  }
  s[j] = '\0';
}
