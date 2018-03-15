#include "func.h"

int main(int argc,char *argv[])
{
	char *arr[2]={argv[2],NULL};
	execv(argv[1],arr);
	printf("you can't see me\n");
	return 0;
}
