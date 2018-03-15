#include "func.h"

void print()
{
	printf("I am print\n");
	abort();
}
int main()
{
	int i=10;
	pid_t pid;
	pid=fork();
	if(0==pid)
	{
		printf("I am child,mypid=%d,myppid=%d\n",getpid(),getppid());
		print();
		printf("after print,I am child\n");
		return 0;
	}else{
		printf("I am parent,pid=%d,mypid=%d\n",pid,getpid());
		int status;
		wait(&status);
		if(WIFEXITED(status))
		{
			printf("exit status=%d\n",WEXITSTATUS(status));
		}else{
			printf("child process dump\n");
		}
		return -1;
	}
}
