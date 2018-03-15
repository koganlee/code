#include "apue.h"

void ouch(int sig);
int main()
{
    struct sigaction act;
       
	act.sa_handler = ouch;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
   sigset_t sign;
   sigemptyset(&sign);
   sigaddset(&sign, SIGINT);
      sigaction(SIGINT, &act, 0);


   sigprocmask(SIG_BLOCK, &sign, NULL);

   sleep(3);
   
   sigpending(&sign);
      

    if(sigismember(&sign, SIGINT))
	{
	    printf("I got signal INT\n");
	}
	else {
	    printf("No signal\n");
	}
 
    sigprocmask(SIG_UNBLOCK, &sign, NULL);	
    sigaction(SIGINT, &act, 0);


    while(1);
	return 0;
	}

void ouch(int sig)
{
   printf("begin\n");
   printf("I got signal %d\n", sig);
   printf("quit\n");
}

