#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/sem.h>

int main()
{
	int semid = semget((key_t) 1234, 1, IPC_CREAT|0600);

	if( semid == -1) {
		perror("Error\n");
		return -1;
	}

	int ret;
	ret = semctl(semid, 0, SETVAL, 2);
	printf("semval = %d\n", ret);
	if(ret == -1) {
		perror("Error2\n");
		return -1;
	}
	ret = semctl(semid, 0, GETVAL);
	if( ret == -1) {
		perror("Error3\n");
		return -1;
	}

	printf("semval = %d\n", ret);
	return 0;
}

