#include "apue.h"
int main(int argc, char *argv[])
{
  if(argc != 2) {
	  printf("Error args\n");
	  return -1;
  }

  int res;
  struct in_addr addr;
  res = inet_aton(argv[1] , &addr);
  printf("res = %d\n", res);
  printf("addr.s_addr=%x\n", addr.s_addr);
  printf("ip=%s\n", inet_ntoa(addr));

 return 0;

}
