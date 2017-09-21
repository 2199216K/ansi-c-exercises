#include <stdio.h>

/*  Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits
    that begin at position p inverted (i.e., 1 changed into 0 and vice versa),
    leaving the others unchanged.   */

unsigned invert(unsigned x, int p, int n);

int main(){
  /*  //For testing purposes
  unsigned testx = 240;       // 11110000 binary
  int testp = 7;              // select from bit 7
  int testn = 3;              // select 3 bits, right-adjusted
  unsigned assertEqual = 16; // correct change [111]10000 -> [000]10000 = 16
  if (invert(testx,testp,testn) == assertEqual){
    printf("Test Passed\n");
  }
  else{
    printf("Test Failed\n");
  }
  */
 return 0;
}

/* inverts n of x's bits from p */
unsigned invert(unsigned x, int p, int n){

  return x ^ (~(~0 << n) << (p+1-n));
}
