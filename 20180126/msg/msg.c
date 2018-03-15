#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <sys/msg.h>
#define  SIZE  20
int main()
{
     int msgid;

	 msgid = msgget((key_t) 1234, IPC_CREAT | 0600);

	 if( msgid == -1) {
		 printf("Error\n");
		 return -1;
	 }
     char s[SIZE];

	 bzero(s, sizeof(s));

	 if(!fork()) {
	      msgrcv(msgid,s, SIZE, 0, 0);  
          printf("%s\n",s );
		  return 0;
	 }
     else{
      printf("Enter messages:\n"); 
      scanf("%s", s);
      msgsnd(msgid,s, SIZE, 0 );

	  wait(NULL);
	 int id = msgctl(msgid, IPC_RMID, NULL);
	 if( id == -1) {
		 printf("error\n");
		 return -1;
	 }

     printf("End\n");
     return 0;
	 }
     	 
	 return 0;
}
