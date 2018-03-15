#include "func.h"
int main()
{
	int i=10;
	char *p=(char*)malloc(10);
	strcpy(p,"hello");
	pid_t pid;
	pid=fork();
	if(0==pid)
	{
		printf("I am child,mypid=%d,myppid=%d\n",getpid(),getppid());
		printf("I am child %s,%p\n",p,p);
		return 0;
	}else{
		printf("I am parent,pid=%d,mypid=%d\n",pid,getpid());
		printf("I am parent %s,%p\n",p,p);
		strcpy(p,"world");
		printf("I am parent %s,%p\n",p,p);
		wait(NULL);
		return 0;
	}
}
