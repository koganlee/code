#include "apue.h"

void ouch(int sig);
int main()
{
    struct sigaction act;
      
	act.sa_handler = ouch;
	sigemptyset(&act.sa_mask);
    sigaddset(&act.sa_mask, SIGQUIT);
	act.sa_flags = 0;

	sigaction(SIGINT, &act, 0);


    while(1);
    {

	}
	return 0;
	}

void ouch(int sig)
{
   printf("begin\n");
   printf("I got signal %d\n", sig);
   sleep(3);
   
   sigset_t sign;
   sigemptyset(&sign);

   sigpending(&sign);
   if(sigismember(&sign, SIGQUIT))
	{
	    printf("I got signal\n");
	}
	else {
	    printf("No signal\n");
	}
   
  printf("quit\n");
}

