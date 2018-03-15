#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>
#define N  10000000

int main()
{
	int shmid = shmget((key_t) 1234, 4096, IPC_CREAT | 0600);
	
	if(shmid == -1) {
		printf("Error\n");
		return -1;
	}
    
//	printf("shmid = %d\n", shmid);

	char  *ptr;
    ptr = (char *) shmat(shmid, NULL, 0);
     
	if((int *) ptr == (int*)-1)
    {
		perror("Error\n");
		return -1;
	}
    
    strcpy(ptr, "How are you");

     printf("ptr = %s\n", ptr);

     

     printf("bye\n"); 
	return 0;
}
