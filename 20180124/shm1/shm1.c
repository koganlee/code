#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define PERM S_IRUSR|S_IWUSR

int main(int argc, char *argv[])
{
	int shmid = shmget(IPC_PRIVATE, 1024, PERM);

	if(shmid == -1) {
	   fprintf(stderr, "Can't create shared memory!\n");
	   exit(EXIT_FAILURE);
	}

	if(fork()) {
		char *p_addr = (char*) shmat(shmid, NULL, 0);
		memset(p_addr, '\0', 1024);
		strncpy(p_addr, "shared memory", 1024);
		printf("Parent:%d Write buffer: %s\n", getpid(), p_addr);
		sleep(2);
	    wait(NULL);
		shmctl(shmid, IPC_RMID, 0);
		exit(0);
	}
	else {
	   sleep(5);
	   char *c_addr = (char *)shmat(shmid, NULL, 0);
	   printf("Client pid = %d, shmid = %d Read buffer :%s\n", getpid(), shmid, c_addr);
	   exit(0);
	}
}
