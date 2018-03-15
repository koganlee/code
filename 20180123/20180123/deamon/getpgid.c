#include "func.h"
int main()
{
	pid_t pid;
	pid=fork();
	if(0==pid)
	{
		printf("I am child,mypid=%d,myppid=%d,pgid=%d\n",getpid(),getppid(),getpgid(0));
		setpgid(0,0);
		printf("I am child,mypid=%d,myppid=%d,pgid=%d\n",getpid(),getppid(),getpgid(0));
		while(1);
		return 0;
	}else{
		printf("I am parent,pid=%d,mypid=%d,pgid=%d\n",pid,getpid(),getpgid(0));
		while(1);
		wait(NULL);
		return 0;
	}
}
