/*The function strrindex(s,t) returns the rightmost occurance of t in s, or -1 if there is none. This is exercise 4-1 in Kernighan and Ritchie "The C Programming Language," Second Edition
 */
#include <stdio.h>

int strrindex(char s[],char t)
{
  int i, index;
  index = -1;
  for(i=0; s[i] != '\0'; i++)
    {
      if(s[i] == t)
	{
	  index = 1;
	}
    }
  return index;
}
