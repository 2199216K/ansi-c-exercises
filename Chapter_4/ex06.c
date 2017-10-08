#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>   /* for atof() */
#include <math.h>
#include <string.h>

/*  Exercise 4-6. Add commands for handling variables. (It's easy to provide
    twenty-six variables with single-letter names.) Add a variable for the most
    recently printed value.

    (use the flag -lm to compile)  */

#define MAXOP   100   /* max side of operand or operator */
#define NUMBER  '0'   /* signal that a number was found */
#define NAME    '1'   /* signal that a function name was found */

int getop(char []);
void push(double);
double pop(void);
void clear_stack(void);

/* reverse Polish calculator */
int main ()
{
  int type, var=0;
  double op1, op2, v;
  char s[MAXOP];
  double variable[26];

  while ((type = getop(s))!= EOF){
    switch (type){
      case NUMBER:
        push(atof(s));
        break;
      case NAME:
        if (strcmp(s,"sin") == 0)
          push(sin(pop()));
        else if (strcmp(s,"cos") == 0)
          push(cos(pop()));
        else if (strcmp(s,"exp") == 0)
          push(exp(pop()));
        else if (strcmp(s,"pow") == 0){
          op2 = pop();
          push(pow(pop(),op2));
        }
        else
          printf("error: %s is not supported \n", s);
        break;
      case '?':
        printf("\t%.8g\n", op2 = pop());
        push(op2);
        break;
      case '&':
        op2 = pop();
        push(op2);
        push(op2);
        break;
      case '$':
        op2 = pop();
        op1 = pop();
        push(op2);
        push(op1);
        break;
      case '#':
        clear_stack();
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        op2 = pop();
        if (op2 != 0.0)
          push(pop() / op2);
        else
          printf("error: zero divisor\n");
        break;
      case '%':
        op2 = pop();
        op1 = pop();
        if (op2 != 0.0)
          push(op1 - op2 * ((int)(op1 / op2)));
        else
          printf("error: zero divisor\n");
        break;
      case '=':
        pop();
        if (var >= 'A' && var <= 'Z')
          variable[var-'A'] = pop();
        else
          printf("error: variable doesnt exit\n");
        break;
      case '\n':
        v = pop();
        printf("\t%.8g\n", v);
        break;
      default:
        if(type >= 'A' && type <= 'Z')
          push(variable[type-'A']);
        else if (type == '@')
          push(v);
        else
          printf("error: unknown command %s\n", s);
        break;
      }
      var = type;
    }
    return 0;
}

#define MAXVAL 100  /* maximum depth of val stack */

int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */

/* clear_stack: clears stack by setting sp = 0 */
void clear_stack(void)
{
  sp = 0;
}

/* push: push f onto value stack */
void push(double f)
{
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
  if (sp > 0)
    return val[--sp];
  else{
    printf("error: stack empty\n");
    return 0.0;
  }
}


int getch(void);
void ungetch(int);

/* getop: get next character or numeric operand */
int getop(char s[])
{
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';

  i = 0;
  if (islower(c)){
    i = 0;
    while (islower(s[++i] = c = getch()))
      ;
    if (c != EOF)
      ungetch(c);
    s[i] = '\0';
    if (strlen(s) > 1)
      return NAME;
    else
      return c;

  }
  if (!isdigit(c) && c != '.' && c != '-')
    return c;     /* not a number */
  if (c == '-'){
    if (isdigit(c = getch()) || c == '.')
      s[++i] = c;
    else{
      if (c != EOF)
        ungetch(c);
      return '-';
    }
  }
  if (isdigit(c)) /* collect integer part */
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.')   /* collect fraction part */
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if (c != EOF)
    ungetch(c);
  return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];    /* buffer for ungetch */
int bufp = 0;         /* next free position in buf */

int getch(void)       /* get a (possibly pushed-back) character */
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)   /* push character back on input */
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}
