#include <stdio.h>
# define O_Bracket '{'
# define C_Bracket '}'
# define MAX_BRKTS 1000

int brkt_indx;
int opn_brkts[MAX_BRKTS];

/* 
   If an open bracket is read, the line number is recorded
   If a close bracket is read, it balances the last open bracket
   so the index is reduced by 1 to point to the current unbalanced
   open brackt
*/
int is_bracket(char c, int line_num){
  extern int opn_brkts[];
  extern int brkt_indx;
  if (c == O_Bracket){
    opn_brkts[brkt_indx] = line_num;
    printf("Open bracket for index %d on line %d\n", brkt_indx, opn_brkts[brkt_indx]);
    return ++brkt_indx;
  }
  else if (c == C_Bracket){
    printf("Close bracket for index %d on line %d\n", brkt_indx, opn_brkts[--brkt_indx]);
    return brkt_indx;
  }
  else
    return 0;
}

int is_comment(char current, char previous){
  
  if (current == '*' && previous == '/' )
    return 1;
  else if (current == '/' && previous == '*')
    return -1;
  else
    return 0;
}
/* copy input to output; 1st version */
int main()
{
  extern int brkt_indx;
  extern int opn_brkts[];

  char c = '\0'; /*character being read*/
  char p = '\0'; /*previous character read*/
  int brackets = 0; /*index of the last unpaired bracket*/
  int comments = 0; /*counts the number of comments open/close found*/
  int line_number = 1;
  int char_number = 0;
  brkt_indx = 0;
  
  while ((c = getchar()) != EOF) {
    if ((brackets = is_bracket(c, line_number)) < 0){
      printf("Extra close braket on line %d\n", line_number);
      return brackets;
    }
    comments = comments + is_comment(c,p);
    if (c == '\n'){
      ++line_number;
      char_number = 0;  
    }
    else
      ++char_number;
    p = c;
  }
  if (comments != 0)
    printf("there is an open comment in your program\n");
  if (brackets !=0)
    printf("Open bracket on line %d\n", opn_brkts[brkt_indx]);
  
  return 0;
}
