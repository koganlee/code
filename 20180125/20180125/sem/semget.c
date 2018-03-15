#include "func.h"

int main()
{
	int semid;
	semid=semget(1234,1,IPC_CREAT|0600);
	if(-1==semid)
	{
		perror("semget");
		return -1;
	}
	return 0;
}
