#include <stdio.h>
#include <stdlib.h>
int main()
{
   system("ls -l");
   system("sleep 10");
   printf("after ls\n");

   return 0;
}
