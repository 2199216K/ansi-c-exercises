#include <stdio.h>
/*  Exercise 1-4. Write a program to print the corresponding Celsius to
    Fahrenheit table. */
    
/* celsius to Fahrenheit table float
  with title */
int main()
{
  float fahr, celsius;
  float lower, upper, step;

  lower = 0;    /* lower limit of temperature scale */
  upper = 300;  /* upper limit */
  step = 20;    /* step size */

  celsius = lower;
  printf(" C \tF\n");
  while (celsius <= upper){
    fahr = (9.0/5.0 * celsius) + 32.0;
    printf("%3.0f %6.1f\n", celsius, fahr);
    celsius = celsius + step;
  }

}
