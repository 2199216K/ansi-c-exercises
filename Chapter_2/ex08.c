#include <stdio.h>
#include <limits.h>

/*  Exercise 2-8. Write a function rightrot(x,n) that returns the value of the
    integer x rotated to the right by n positions. */

unsigned rightrot(unsigned x, int n);

int main(){
  /*  //For testing purposes
  unsigned testx = 240;       // 11110000 binary
  int testn = 2;              // rotate 2 times
  unsigned assertEqual = 60;  // correct change 11110000 -> 00111100 = 60
  if (rightrot(testx,testn) == assertEqual){
    printf("Test Passed\n");
  }
  else{
    printf("Test Failed\n");
  }
  */

 return 0;
}

/* right rotate n times */
unsigned rightrot(unsigned x, int n){
  unsigned y, z; // to save integers that will loop round and ones that wont

  y = x >> n;        // for the bits that dont loop round to the leftmost bit
  z = x << (sizeof(unsigned) * CHAR_BIT - n); /* size of unsigned * char size =
                                           bits in unsigned(loop round bits) */

  return y | z;     // Union of y and z
}
