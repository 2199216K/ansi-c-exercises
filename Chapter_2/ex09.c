#include <stdio.h>

/*  Exercise 2-9. In a two's complement number system, x &= (x-1) deletes
    the rightmost 1-bit in x. Explain why. Use this observation to write a
    faster version of bitcount. */

int bitcount(unsigned x);

/* Explanation
    x &= (x-1) <==> x = x & (x-1)
    since (x-1) inverts the last 1 to a 0 or 0 to a 1(inverting 0s until it
          inverts a 1) and then & compares the decremented int to the original
          and keeps the bits that didn't change.

          Example:
          Assume x=12:  (x-1)            then      x & (x-1)
                       12   01100               12   01100
                       -1   00001              &11   01011
                       ==========              ===========
                       11   01011               8    01000
*/

int main(){
  /* //For testing purposes
  unsigned testx = 12;  // 12 = 00001100
  int assertEquals = 2; // two 1-bit digits in 12
  if (bitcount(12) == assertEquals){
    printf("Test passed\n");
  }
  else{
    printf("Test failed\n");
  }
  */

  return 0;
}


/* bitcount: count 1 bits in x */
 int bitcount(unsigned x){
   int b;
   for (b = 0; x != 0; x &= (x-1)){
     ++b;
   }
   return b;
 }
