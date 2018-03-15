#include "func.h"
int main()
{
	pid_t pid;
	pid=fork();
	if(0==pid)
	{
		printf("I am child,mypid=%d,myppid=%d,pgid=%d,sid=%d\n",getpid(),getppid(),getpgid(0),getsid(0));
		setsid();
		printf("I am child,mypid=%d,myppid=%d,pgid=%d,sid=%d\n",getpid(),getppid(),getpgid(0),getsid(0));
		while(1);
		return 0;
	}else{
		printf("I am parent,pid=%d,mypid=%d,pgid=%d,sid=%d\n",pid,getpid(),getpgid(0),getsid(0));
		while(1);
		wait(NULL);
		return 0;
	}
}
