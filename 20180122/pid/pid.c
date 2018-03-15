#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
    printf("pid:%d ppid:%d\n", getpid(), getppid());
	return 0;
}
