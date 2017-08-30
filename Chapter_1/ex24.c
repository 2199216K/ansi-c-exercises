#include <stdio.h>

/*  Exercise 1-24. Write a program to check a C program for rudimentary syntax
    errors like unmatched parentheses, brackets and braces. Don't forget about
    quotes, both single and double, escape sequences, and comments.
    (This program is hard if you do it in full generality.) */

void SyntaxChecker(int c);            // Searches for comments or quotes
void TraverseComment(void);           // Removes /* */ style comments
void TraverseSingleLineComment(void); // Removes // (single line) comments
void TraverseQuote(int c);            // Traverses Quotes to end
void CheckEnclosures(int c);          // Tallys enclosures and checks them

int parentheses;                      // Global var for parentheses
int brackets;                         // Global var for brackets
int braces;                           // Global var for braces


int main(){

  int c;

  braces = brackets = parentheses = 0;  // initialise variables
  while ((c = getchar()) != EOF){
    SyntaxChecker(c);
  }
  if (parentheses > 0){
    printf("Unmatched parentheses: Missing %d closing parentheses.\n", parentheses);
  }
  if (brackets > 0){
    printf("Unmatched brackets: Missing %d closing brackets.\n", brackets);
  }
  if (braces > 0){
    printf("Unmatched braces: Missing %d closing braces.\n", braces);
  }

  return 0;
}

void SyntaxChecker(int c){
  int d;

  if (c == '/'){
    d = getchar();      // If a slash is found, check next character

    if (d == '*')       // check if comment is normal or single line
      TraverseComment();
    else if (d == '/')
      TraverseSingleLineComment();
    else{               // if its not a comment, check both characters
      CheckEnclosures(c);
      CheckEnclosures(d);
    }
  }

  else if (c == '\'' || c == '"'){    // check if entering quoted string
    TraverseQuote(c);
  }

  else{           // if its not a comment or start of check for enclosures
    CheckEnclosures(c);
  }
}

void TraverseComment(void){
  int c,d;

  c = getchar();
  d = getchar();
  while(c != '*' || d != '/'){  // traverse comment until */ combination
    c = d;
    d = getchar();
  }
}

void TraverseSingleLineComment(void){
  int c;

  while((c = getchar())!= '\n') // traverse comment until c = '\n'
    ;
}

void TraverseQuote(int c){
  int d;

  while((d = getchar())!= c){   // until same closing quote is reached
    if (d == '\\')              // if escape character if found
      getchar();                // bypass by ignoring next character
  }
}

void CheckEnclosures(int c){
  switch (c) {
    case ')':
      --parentheses;
      if (parentheses < 0){
        printf("Unmatched parentheses: Missing opening parenthesis.\n");
        parentheses = 0;
      }
      break;

    case ']':
      --brackets;
      if (brackets < 0){
        printf("Unmatched brackets: Missing opening bracket.\n");
        brackets = 0;
      }
      break;

    case '}':
      --braces;
      if (braces < 0){
        printf("Unmatched braces: Missing opening brace.\n");
        braces = 0;
      }
      break;

    case '(':
      ++parentheses;
      break;

    case '[':
      ++brackets;
      break;

    case '{':
      ++braces;
      break;
  }
}
