#include <stdio.h>

/*  Exercise 1-23. Write a program to remove all comments from a C program.
    Don't forget to handle quoted strings and character constants properly.
    C comments don't nest. */

void SearchForComment(int c);       // Searches for comments or quotes
void RemoveComment(void);           // Removes /* */ style comments
void RemoveSingleLineComment(void); // Removes // (single line) comments
void TraverseQuote(int c);          // Traverses Quotes to end

int main(){

  int c;

  while ((c = getchar()) != EOF){
    SearchForComment(c);
  }
  return 0;
}

void SearchForComment(int c){
  int d;

  if (c == '/'){
    d = getchar();      // If a slash is found, check next character

    if (d == '*')       // check if comment is normal or single line
      RemoveComment();
    else if (d == '/')
      RemoveSingleLineComment();
    else{               // if its not a comment print both characters
      putchar(c);
      putchar(d);
    }
  }

  else if (c == '\'' || c == '"'){    // check if entering quoted string
    TraverseQuote(c);
  }

  else{           // if its not a comment or start of quote print char
    putchar(c);
  }
}

void RemoveComment(void){
  int c,d;

  c = getchar();
  d = getchar();
  while(c != '*' || d != '/'){  // traverse comment until */ combination
    c = d;
    d = getchar();
  }
}

void RemoveSingleLineComment(void){
  int c;

  while((c = getchar())!= '\n') // traverse comment until c = '\n'
    ;
  putchar(c);                   // print c (which can only be '\n')
}

void TraverseQuote(int c){
  int d;

  putchar(c);                   // print quote
  while((d = getchar())!= c){   // until same closing quote is reached
    putchar(d);                 // print characters in the quotes
    if (d == '\\')              // if escape character if found
      putchar(getchar());       // bypass by printing next character
  }
  putchar(d);                   // print closing quote
}
