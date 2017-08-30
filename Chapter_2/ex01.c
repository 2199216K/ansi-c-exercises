#include <stdio.h>
#include <limits.h>
#include <float.h>

/*  Exercise 2-1. Write a program to determine the ranges of char, short, int,
    and long variables, both signed and unsigned, by printing appropriate
    values from standard headers and by direct computation. Harder if you
    compute them: determine the ranges of the various floating-point types. */

int main(){
  printf("The range of UNSIGNED CHAR is: 0 to %d\n", UCHAR_MAX);
  printf("The range of SIGNED CHAR is: %d to %d\n\n", SCHAR_MIN, SCHAR_MAX);

  printf("The range of UNSIGNED SHORT is: 0 to %d\n", USHRT_MAX);
  printf("The range of SIGNED SHORT is: %d to %d\n\n", SHRT_MIN, SHRT_MAX);

  printf("The range of UNSIGNED INT is: 0 to %u\n", UINT_MAX);
  printf("The range of SIGNED INT is: %d to %d\n\n", INT_MIN, INT_MAX);

  printf("The range of UNSIGNED LONG is: 0 to %lu\n", ULONG_MAX);
  printf("The range of SIGNED LONG is: %ld to %ld\n\n", LONG_MIN, LONG_MAX);

  printf("The range of FLOAT is: %.10e to %.10e\n", FLT_MIN, FLT_MAX);
  printf("The range of DOUBLE is: %.10e to %.10e\n", DBL_MIN, DBL_MAX);
  printf("The range of LONG DOUBLE is: %.10Le to %.10Le\n", LDBL_MIN, LDBL_MAX);

  return 0;

}
