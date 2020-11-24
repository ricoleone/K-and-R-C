#include <stdio.h>


unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);


unsigned getbits(unsigned x,int p,int n){
  return (x >> (p+1-n)) & ~(~0 << n);
}
  
int main()
{
  printf("x=256, p=4, n=3, getbits=%u\n", getbits(255,4,3));
}


