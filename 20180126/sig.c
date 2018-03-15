#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void ouch (int sig)
{
    printf("begin OUCH!- I got signal %d\n", sig); 
    sleep(3);
	printf("end  OUCH!- I got signal %d\n", sig);
}

int main()
{
	struct sigaction act;

	act.sa_handler = ouch;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;//SA_NODEFER | SA_SIGINFO;

	sigaction(SIGINT, &act, 0);

	while(1) {
	 printf("Hello World!\n");
	 sleep(1);
	}
}


