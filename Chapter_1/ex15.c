#include <stdio.h>

/*  Exercise 1.15. Rewrite the temperature conversion program of Section 1.2 to
    use a function for conversion. */

float TempConverter(float temp, int isCelsius);

/* test for C and F function */
int main()
{
  int i;

  printf("temp ->C ->F \n");
  for (i = 0; i <= 200; i = i + 20)
    printf("%4d %3.0f %3.0f\n", i, TempConverter(i,0),TempConverter(i,1));
  return 0;
}

/* temperature converter. isCelsius denotes if its Celsius or not */
float TempConverter(float temp, int isCelsius)
{
  float result;
  if (isCelsius == 1){
    result = (9.0 / 5.0 * temp) + 32.0;
  }
  else {
    result = (5.0 / 9.0) * (temp - 32.0);
  }
  return result;
}
