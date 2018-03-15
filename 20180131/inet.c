#include "apue.h"

int main(int argc, char *argv[])
{
   if(argc != 2) {
	   printf("Error args\n");
	   return -1;
   }


     printf("%x\n", inet_addr(argv[1]));

   return 0;
}
