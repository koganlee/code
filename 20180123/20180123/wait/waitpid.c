#include "func.h"
//通过status获取返回值
int main()
{
	pid_t pid;
	pid=fork();
	if(0==pid)
	{
		printf("I am child,mypid=%d,myppid=%d\n",getpid(),getppid());
		sleep(10);
		return 5;
	}else{
		printf("I am parent,pid=%d,mypid=%d\n",pid,getpid());
		int status;
		pid_t pid_recycle;
		pid_recycle=waitpid(-1,&status,WNOHANG);
		if(WIFEXITED(status))
		{
			printf("exit status=%d\n",WEXITSTATUS(status));
		}else{
			printf("child process dump\n");
		}
		printf("pid_recycle=%d\n",pid_recycle);
		return 0;
	}
}
