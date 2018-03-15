#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
int main()
{
	int i=10;
	pid_t pid;
	pid=fork();
	if(0==pid)
	{
		printf("I am child,mypid=%d,myppid=%d\n",getpid(),getppid());
		while(1);
		return 0;
	}else{
		printf("I am parent,pid=%d,mypid=%d\n",pid,getpid());
		return 0;
	}
}
