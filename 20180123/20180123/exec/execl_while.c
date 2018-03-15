#include "func.h"

int main(int argc,char *argv[])
{
	sleep(10);
	execl(argv[1],argv[2],NULL);
	printf("you can't see me\n");
	return 0;
}
