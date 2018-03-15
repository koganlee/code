#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("Parent processs id:%d\n", getpid());
	pid_t iRet = fork();
	if( iRet < 0) {
			printf("Creat child process fail!\n");
	}else if(iRet == 0) {
			printf("Child process id:%d ppid:%d\n", getpid(), getppid());
	}else {
			printf("Parent process success, child id:%d\n",iRet);
	}
	return 0;
}
