#include <stdio.h>

/* copy input to output; 1st version */
int main()
{

     long nc;

     nc = 0;
     while (getchar() != EOF) {
        ++nc;
     }
     printf("%ld\n", nc);
     return 0;
}
