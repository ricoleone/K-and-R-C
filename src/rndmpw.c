/******************************************************************************
 * Name: rndmpw
 * Description: returns a 16 character random password
 * Usage: rndmpw
 * Enhancements: this method will be updated to allow the user to
 *               specify the number of characters, where 16 will be the
 *               default. The user will also be able to specify characters
 *               that should not be included, and to specify the range
 *               of ascii characters used in the password  
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

char randchr( int );

char randchr( int seed )
{
  int c = 0;
  int max = 126; /*printable ascii characters have value between 33 and 126 */
  int min = 33;
    
  srand( time( NULL ) * (seed * seed) );
  c = rand();
  c %= (max + 1 - min); /* sets 0 <=  c < 94 */
  c += min; /* sets 33 <= c < 127, the full range of ascii characters that map to the keyboard*/
  return c;
}

int main(int argc, char *args[]){

  /* used to generate a random seed for the random char function */
  struct timeval start, end;
  
  int size = 16;
  char pw[size + 1];
  pw[0] = randchr( time( NULL ) );
  gettimeofday( &start, NULL );
  for( int i = 1; i <= size; i++ ){
    gettimeofday( &end, NULL );
    pw[i] = randchr( pw[i-1] * ( end.tv_usec - start.tv_usec ) );
  }
  pw[size] = '\0';
  printf("%s\n", pw );
  return 0;
}
