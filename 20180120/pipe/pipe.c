#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/times.h>
#include <fcntl.h>
#include <string.h>
int main(int argc, char *argv[])
{
  
  if(argc != 3){
	 perror("Error\n");
     exit(EXIT_FAILURE);
   }
   int fifofdr = open(argv[1], O_RDONLY);
   int fifofdw = open(argv[2], O_WRONLY);
   if(fifofdr == -1)
   {
      perror("error\n");
      exit(EXIT_FAILURE);
   }
   if(fifofdw == -1)
   {
      perror("error\n");
      exit(EXIT_FAILURE);
   }

   printf("Write port\n");
   
   char buf[128] = {0};
   fd_set rdset;
   int res = 0;
    while(1)
	  {	
         FD_ZERO(&rdset);
		 FD_SET(0, &rdset);
		 FD_SET(fifofdr, &rdset);
         res = select(fifofdr + 1, &rdset, NULL, NULL, NULL);
     if( res > 0) {
		if(FD_ISSET(0, &rdset)) {
	       memset(buf, 0, sizeof(buf));
	       res = read(0, buf, sizeof(buf));
		if(res == 0) {	   
           printf("Bye\n");
           close(fifofdr);
           close(fifofdw);
		   break;
		 }
		 write(fifofdw, buf, strlen(buf) - 1);	
	  }
        if(FD_ISSET(fifofdr, &rdset)) {	
        	memset(buf, 0, sizeof(buf));  
	        res = read(fifofdr, buf, sizeof(buf));		
        if( res == 0) { 
           printf("Bye\n");
           close(fifofdr);
           close(fifofdw);
		   break;
		 }
          printf("%s\n", buf); 
	    }
	  }	
	}
   exit(EXIT_SUCCESS);
}
