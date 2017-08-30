#include <stdio.h>

/*  Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the
    n bits that begin at position p set to the rightmost n bits of y, leaving
    the other bits unchanged.  */

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(){
  /*  For testing purposes
  unsigned testx = 240;       // 11110000 binary
  unsigned testy = 49;        // 00110001 binary
  int testp = 5;              // select from bit 5
  int testn = 3;              // select 3 bits
  unsigned assertEqual = 200; // correct change 11[110]000 -> 11[001]000 = 200
  if (setbits(testx,testp,testn,testy) == assertEqual){
    printf("Test Passed\n");
  }
  else{
    printf("Test Failed\n");
  }
 */
 return 0;
}

/* returns x with n bits from p set to y's rightmost bits  */
unsigned setbits(unsigned x, int p, int n, unsigned y){

  return x & ~(~(~0 << n)  << (p+1-n)) |
        (y &   ~(~0 << n)) << (p+1-n);
}
