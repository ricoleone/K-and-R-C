#include <stdio.h>

int htoi(char hex[]){
  char current = '\0';
  char previous = '\0';

  int i, n;
  n=0;
  for(i=0; (hex[i] >= '0' && hex[i] <= '9') ||(hex[i] >= 'a' && hex[i] <= 'f') || (hex[i] >= 'A' && hex[i] <= 'F') ; ++i){
    if(hex[i] >='A' && <='F'){
      n= 16*n + (hex[i] - 'A' + 11);
    }
    else if(hex[i]>= 'a' && hex[i] <= 'f'){
      n = 16*n + (hex[i] - 'a' + 11);
    }
    else{
      n = 16*n + (hex[i] - '0');
    }
    
  

    }
