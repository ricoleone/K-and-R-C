/*The purpose of the module is to remove comments from source code*/
#include <stdio.h>

int main(){
  
  int currnt_c = '\0';
  int prev_c = '\0';
  typedef enum {false, true} boolean;
  boolean commnt;
  commnt = false;

  while( (currnt_c = getchar()) != EOF){

    /*check if a comment is starting?*/ 
    if( currnt_c == '/' && commnt == false){
      prev_c = currnt_c;
      if( (currnt_c = getchar()) == EOF){
	return 0;
      }
      if( currnt_c == '*' && prev_c == '/') {
      commnt = true;
      }
      else{
	putchar(prev_c);
	putchar(currnt_c);
      }
    }
    /*check if a comment is ending*/
    else if(currnt_c == '*' && commnt == true){
      prev_c = currnt_c;
      if((currnt_c = getchar()) == EOF){
	return 0;
      }
      if(currnt_c == '/' && prev_c == '*') {
	commnt = false;
	
         if((currnt_c = getchar()) == EOF){
	   return 0;
         }
         /*remove the newline is comment was on it's own line*/
         if(currnt_c != '\n'){
	   putchar(currnt_c);
         }
      }
      else{
	putchar(prev_c);
	putchar(currnt_c);
      }
    }
    else if(commnt == false)
      putchar(currnt_c);
    
    prev_c = currnt_c;
  }
}
