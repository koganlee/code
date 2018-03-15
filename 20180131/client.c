#include "apue.h"

int main(int argc, char *argv[])
{
  if(argc != 3) {
	  printf("Error args\n");
	  return -1;
  }
  int sfd;
  sfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sfd == -1) {
	  perror("Failure\n");
	  return -1;
  }

  struct sockaddr_in  server;
  bzero(&server, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_port = htons(atoi(argv[2]));
  server.sin_addr.s_addr = inet_addr(argv[1]);

  int res = connect(sfd, (struct sockaddr *)&server, sizeof(struct sockaddr));
  if( res == -1){
	  printf("connect\n");
	  return -1;
  }

   return 0;
}
