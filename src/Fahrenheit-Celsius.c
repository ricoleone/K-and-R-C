#include <stdio.h>
#define LOWER 0   /* lower limit of temperature table*/
#define UPPER 300 /* Upper limit of temperature table */
#define STEP 20   /* step size */
/* print Fehrenheit-Celsius Table for Fahr = 0, 20, ..., 300 */

int main()
{
  float fahr, celsius;
  int lower, upper,step;

  
  fahr = LOWER;
  while (fahr <= UPPER) {
    celsius = (5.0/9.0) * (fahr - 32.0);
    printf("%3.0f %6.1f\n", fahr, celsius);
    fahr = fahr + STEP;
  
  }
  return 0;
}
