#include <stdio.h>

/* copy input to output; 1st version */
int main()
{

    int c;

    printf("The value of EOF is %d\n", EOF);
    while ((c = getchar())!= EOF) {
      putchar(c);
      
  }
  return 0;
}
