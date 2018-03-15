#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if(argc != 2){
		perror("error\n");
		return -1;
	}

	int fd = open(argv[1],O_RDWR);
	if( fd == -1) {
      perror("Cant 't open\n");
	  return -1;
	}
    char s[50];
	printf("Do you want to change this file? enter some sentence\n");
    scanf("%s", s);

	int fd1 = write(fd, s, strlen(s));
	if(fd1 == -1){
		perror("Can't write\n");
		return -1;
	}
    else
	{
		puts("successful\n");
	}

	return 0;
}
