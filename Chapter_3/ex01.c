#include <stdio.h>
#include <limits.h>
#include <time.h>

/*  Exercise 3-1. Our binary search makes two tests inside the loop, when one
    would suffice (at the price of more tests outside.) Write a version with
    only one test inside the loop and measure the difference in run-time. */

int binsearch_old(int x, int v[], int n);
int binsearch_new(int x, int v[], int n);

int main(void){

  int x = 13, n = 10;
  int v[10] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89};

  clock_t start_old = clock();
  printf("Match at position: %d\n", binsearch_old(x, v, n));
  double cpu_time_used_old = ((double)(clock() - start_old)) / CLOCKS_PER_SEC;
  printf("Run-time for binsearch_old: %f\n\n", cpu_time_used_old);

  clock_t start_new = clock();
  printf("Match at position: %d\n", binsearch_new(x, v, n));
  double cpu_time_used_new = ((double)(clock() - start_new)) / CLOCKS_PER_SEC;
  printf("Run-time for binsearch_new: %f\n\n", cpu_time_used_new);

  printf("Run-time difference: %f\n\n", cpu_time_used_old - cpu_time_used_new);

  return 0;

}

int binsearch_old(int x, int v[], int n){

  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low <= high){
    mid = (low + high) / 2;
    if (x < v[mid]){
      high = mid - 1;
    }
    else if (x > v[mid]){
      low = mid + 1;
    }
    else{
      return mid;
    }
  }
  return -1;
}

int binsearch_new(int x, int v[], int n){

  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low < high){
    mid = (low + high) / 2;
    if (x > v[mid]){
      low = mid + 1;
    }
    else{
      high = mid;
    }
  }
  return (x == v[low]) ? low : x;
}
