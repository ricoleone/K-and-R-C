*/
/ swap(a,b) from K&R Section 5.2
*/

<stdio.h>

swap(a,b);

void swap( int *px, int *py)
{
  int temp;

  temp = *px;
  *px = *py;
  *py = temp;

}  

