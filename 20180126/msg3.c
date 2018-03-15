#include "apue.h"
void ouch(int sig );

int main()
{
   (void)signal(SIGINT, ouch);

   (void)signal(SIGQUIT, ouch);
   while(1) {
    printf("Hello\n");
    sleep(1);
   }
   return 0;
}
void ouch(int sig)
{
     printf("Ouch. I got signal %d\n", sig);
}
