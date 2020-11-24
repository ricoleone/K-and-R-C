/*
 * Author:      Rico Leone
 * Name:        overwrite
 * Description: overwrite a list of files with random characters before deleting 
 *              the file to securely remove the file.
 * Usage:       overwrite <filename> [<filename>]...
 *
 */

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#if DEBUG
   #define DEBUG 1
#else
   #define DEBUG 0
#endif

/* 
 * rand_char returns a random char between 0 and upper
 */
char rand_char(int upper){
  return (char)rand()%upper;
}
int main(int argc, char *argv[])
{
    char c; 
    int fileD, size;
    char *usage = "usage: overwrite <filename> [<filename>]...\n";

    if(argc == 1){
      write(2, usage, 39 );
      exit(1);
    }
    for(int k = 1; k < argc; k++){
      
      if((fileD = open(argv[k], O_RDWR)) == -1){
	perror(argv[k]);
	continue;
      }
      size = lseek(fileD, 0L, SEEK_END) - 1;/*don't count EOF*/
      lseek(fileD, 0L, SEEK_SET);
      srandom(size);
      if(DEBUG){
	   printf("The size of file %s is %d\n", argv[k], size);
	   while(read(fileD,&c,1) == 1)
              printf("%c", c);
	   printf("\n");
	   lseek(fileD, 0L, SEEK_SET);       
      }
      for(int i = 0; i < size; i++){
	 c = rand_char(255);
	 write(fileD,&c,1);
      }
      if(DEBUG){
	   lseek(fileD, 0L, SEEK_SET);
	   while(read(fileD,&c,1) == 1)
              printf("%c", c);
	   printf("\n");
	   lseek(fileD, 0L, SEEK_SET);
      }
      close(fileD);
      unlink(argv[k]);
    }
    exit(0);
}

