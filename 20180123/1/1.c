#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
int main()
{
   pid_t pid;
   pid = fork();

   if(0 == pid  )
   {
		printf(" I am child, mypid = %d, my ppid = %d\n", getpid(), getppid());
		   while(1)
		   {

		   }
   }
  else
   {
      printf(" I am parent, mypid = %d\n", pid);
       while(1)
	   {


	   }
   }
  return 0;
}
