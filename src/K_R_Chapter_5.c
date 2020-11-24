 /*
 / Rico Leone
 / GemmaSphere.com
 / 09/17/2019
 / Kernighan & Ritchie 2nd Edition
*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define ALLOCSIZE 10000 /* Size of available space */

static char allocbuf[ALLOCSIZE]; /* Storage for alloc */
static char *allocp = allocbuf;  /* Next free position */

/***************************
/Section K&R 5.2 
/***************************/

 /* interchange px and py */
void swap( int *px, int *py)
{
  int temp;
  temp = *px;
  *px = *py;
  *py = temp;
}


/* getint: get the next integer from input into *pn 
/  where getch() and ungetch() are from Chapter 4, section 3*/

int getint (int *pn)
{
  int c, sign;

  while (isspace(c = getch())) /* skip white space */
    ;
  if (!isdigit( c ) && c!= EOF && c != '+' && c != '-') {
    ungetch( c );   /* it's not a number */
    return 0;
  }
  sign = (c == '-') ? -1: 1;
  if (c== '+' || c == getch())
    *pn = 10 * *pn + (c - '0');
  *pn *= sign;
  if (c != EOF)
    ungetch(c);
  return c;
}

/* get the length of a string */

int strlen( char *s )
{
  int n;

  for (n = 0; *s != '\0'; s++)
    n++;
  return n;
}

/* K&R 5.4 Address Arithmetic */

char *alloc( int n ) /* Return pointer to n characters */
{
  if ( allocbuf + ALLOCSIZE - allocp >= n ) /* it fits */
    {
      allocp += n;
      return allocp - n /* old p */
	}
  else /* not enough room */
    return 0;
}

void afree( char *p ) /* free storage pointed to by p */
{
  if ( p >= allocbuf && p < allocbuf + ALLOCSIZE )
    allocp = p;
}

/* K&R 5.5 Character Pointers and Functions */

/* strcpy: copy t to s; array subscript version */
void strcpy( char *s, char *t )
{
  int i;

  i = 0;
  while ( (s[i] = ti[i] ) != '\0' )
    i++;

}

/* strcpy: copy t to s; pointer version */
void strcpy( char *s, char *t )
{
  while ((*s = *t) != '\0' )
    {
      s++;
      t++;
    }
}

/* strcpy: copy t to s; better pointer version */
void strcpy( char *s, char *t )
{
  while ((*s++ = *t++) != '\0' )
    ;
}

/* strcpy: copy t to s; even better pointer version */
void strcpy( char *s, char *t )
{
  while ( *s++ = *t++ )
    ;
}
/* strcmp: return < 0 if s<t, 0 if s==t, and >0 is s>t */
int strcmp( char *s, char *t )
{
  int i;

  for ( i = 0; s[i] == t[i]; i++ )
    if ( s[i] == '\0' )
      return 0;
  return s[i] - t[i];
}
/* strcmp: return < 0 if s<t, 0 if s==t, and >0 is s>t (pointer version)*/
int strcmp( char *s, char *t )
{
  for ( ; *s == *t; s++, t++ )
    if ( *s == '\0' )
      return 0;
  return *s - *t;
}

#define MAXLINES 5000 /* max # lines to be sorted */

char *lineptr [MAXLINES]; /* pointers to text lines */

int readlines( char *lineptr[], int nlines );
void writelines( char *lineptr[], int nlines );

void qsort( char *lineptr[], int left, int right );

main()
{
  int nlines; /* number of input lines read */

  if ((nlines = readlines( lineptr, MAXLINES )) >= 0 ) {
    qsort( lineptr, 0, nlines - 1 );
    writelines( lineptr, nlines);
    return 0;
  } else {
    printf( "error: input too big to sort\n" );
    return 1;
  }
}

#define MAXLEN /* max length of any input line */
int getline( char *, int ); /* from Section 1.9 */
char *alloc( int );

/* readlines: read input lines */
int readlines( char *lineptr[], int maxliines )
{
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while (( len = getline( line, MAXLEN )) > 0 )
    if ( nline >= maxlines || (p = alloc( len )) == NULL )
      return -1;
    else {
      line [len - 1] = '\0'; /* delete newline */
      strcpy( p, line );
      lineptr [ nlines++] = p;

    }
  return nlines;
}

/* writelines: write output lines */
void writelines( char *lineptr[], int nlines )
{
  int i;

  for ( i = 0; i < nlines; i++ )
    printf( "%s\n", lineptr[i]);
}

/* writelines: write output lines (poiner version) */
void writelines( char *lineptr[], int nlines )
{
  while ( nlines-- > 0 )
    printf( "%s\n", *lineptr++ );
}
/* qsort: sort v[left] ... v[right] into increasing order */
void qsort( char *v[], int left, int right )
{
  int i, last;
  void swap( char *v[], int i, int j );

  if ( left >= right ) /* do nothing if array contains */
    return;            /* fewer than two elelments */
  swap ( v, left, ( left + right ) / 2 );
  last = left;
  for ( i = left + 1; i < = right; i++ )
    if ( strcmp( v[i], v[left] ) < 0 )
      swap( v, ++last, i );
  swap( v, left, last );
  qsort( v, left, last - 1 );
  qsort( v, last + 1, right );
}

/* swap: interchange v[i] and  v[j] */
void swap( char *v[], int i , int j )
{
  char *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
  
}

static char daytab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from & day */
int day_of_year( int year, int month, int day )
{
  int i, leap;

  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
  for ( i = 1; i < month; i++ )
    day += daytab[leap][i];
  return day;

}

/* month_day: set month, day from day of year */
void month_day( int year, int yesterday, int *pmonth, int *pday )
{
  int i, leap;

  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
  for ( i = 1; yesterday > daytab[leap][i]; i++ )
    yesterday -= daytab[leap][i];
  *pmonth = i;
  *pday = yearday;
}

/* echo command-line arguments; 1st version */

#include <stdio.h>

main(int argc, char *argv[])
{
  int i;

  for ( i = 1; i < argc; i++ )
    printf( "%s%s", argv[i], ( i < argc-1 ) ? " ": "" );
  printf( "\n" );
  return 0;
}
/* echo command-line arguments; 2nd versions */

#include <stdio.h>

main( int argc, char *argv[] )
{
  while( --argc > 0 )
    printf ( "%s%s", *++argv, ( argc < 1 ) ? " ": "" );
  printf ( "\n" );
  return 0;
}

/*find: print lines that match pattern from 1st arg */

#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline( char *line, int max );

main( int argc, char *argv[] )
{
  char line[MAXLINE];
  int found = 0;

  if ( argc != 2 )
    printf( "Usage: find pattern\n" );
  else
    while ( getline( line, MAXLINE ) > 0 )
      if ( strstr ( line, argv[1] ) != NULL ) {
	printf ( "%s", line );
	found++;
      }
  return found;
}
