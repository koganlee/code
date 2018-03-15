#include "func.h"
int main()
{
	int i=10;
	pid_t pid;
	pid=fork();
	if(0==pid)
	{
		printf("I am child,mypid=%d,myppid=%d\n",getpid(),getppid());
		return 0;
	}else{
		printf("I am parent,pid=%d,mypid=%d\n",pid,getpid());
		sleep(10);
		printf("I will recycle\n");
		wait(NULL);
		while(1);
		return 0;
	}
}
