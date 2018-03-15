#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
	 if(!fork())
	 { 
		setsid();//创建新会话
        umask(0);
		int i;
	    for(i=0;i<3;i++)
		{ 
			close(i);
		}
	    while(1)
		{
          int fd;
		  fd = open("/temp/file", O_WRONLY |O_CREAT, 755);
          if(fd == -1)
		  {
			perror("Can't open \n");
            exit(-1);
		  }
          write(fd,"I sleep 3 second", 17);    
          sleep(3);
		}	
 	 }
	 else
	 {
	  exit(0);
    }
}

