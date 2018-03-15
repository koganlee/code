#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc,char* argv[])
{
	printf("uid=%d,gid=%d,euid=%d,egid=%d\n",getuid(),getgid(),geteuid(),getegid());
	int fd=open(argv[1],O_RDWR);
	write(fd,"456",3);
	close(fd);
	return 0;
}
