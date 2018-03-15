#include "func.h"

int main()
{
	int shmid;
	shmid=shmget((key_t)1234,4096,IPC_CREAT|0600);
	if(-1==shmid)
	{
		perror("shmget");
		return -1;
	}
	printf("shmid=%d\n",shmid);
	int ret=shmctl(shmid,IPC_RMID,NULL);
	if(-1==ret)
	{
		perror("shmctl");
		return -1;
	}
	return 0;
}
