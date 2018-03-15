#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <errno.h>
int main()
{
    printf("uid: %d  gid:%d\n", getuid(), getgid());
	printf("eudi:%d egid:%d\n", geteuid(),getegid());

    FILE *fp = fopen("a.txt", "a");
	if( fp == NULL)
	{
	    perror("fopen error\n");
	}

	fputs("world", fp);
	fclose(fp);

	return 0;
}
