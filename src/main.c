#include <stdio.h>
#define MAXLINE 1000

int strrindex(char s[], char t);


int main()
{
    char t = '\0'; 
    char* line = NULL;
    size_t len = 0;
    ssize_t read = 0;
    while (read != -1) {
        puts("enter a line");
        read = getline(&line, &len, stdin);
	printf("The right most position of character %s is  %d\n", t, strrindex(line, t));
        printf("line = %s", line);
        printf("line length = %zu\n", read);
        puts("");
    }
      
  printf("The right most position of character %s is  %d\n", t, strrindex(line, t);
  return 0;
}
				     
