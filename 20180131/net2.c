#include "apue.h"
//#include <netdb.h>
int main(int argc, char *argv[])
{
  if(argc != 3) {
	  printf("Error args\n");
	  return -1;
  }

  struct hostent *ptr;

  ptr = gethostbyname(argv[1]);

  if(ptr == NULL) {
	  printf("gethostbyname h_errno=%d\n", h_errno);
	  return -1;
  }
  printf("h_name = %s\n", ptr -> h_name);
  int n = 0;
  for(n = 0; ptr -> h_aliases[n] != NULL; n++) {
	  printf("%s\n", ptr ->  h_aliases[n]);
  }
  char ip[16] = {0};
  for(n = 0;  ptr -> h_addr_list[n] != NULL; n++) {
	  bzero(ip, sizeof(ip));
	  inet_ntop(ptr -> h_addrtype, ptr -> h_addr_list[n], ip, sizeof(ip));
	  printf("%s\n", ip);
  }
  printf("ptr->h_length=%d\n", ptr -> h_length);
  return 0;
}
