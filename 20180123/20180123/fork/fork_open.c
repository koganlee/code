#include "func.h" 
int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("error args\n");
		return -1;
	}
	int fd=open(argv[1],O_RDWR);
	pid_t pid;
	char buf[128]={0};
	int ret;
	pid=fork();
	if(0==pid)
	{
		printf("I am child,mypid=%d,myppid=%d\n",getpid(),getppid());
		lseek(fd,0,SEEK_SET);
		ret=read(fd,buf,sizeof(buf));
		printf("I am child %d,%s\n",ret,buf);
		return 0;
	}else{
		printf("I am parent,pid=%d,mypid=%d\n",pid,getpid());
		read(fd,buf,sizeof(buf));
		printf("I am parent %s\n",buf);
		sleep(2);
		return 0;
	}
}
