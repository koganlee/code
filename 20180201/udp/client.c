#include "apue.h"

int main(int argc, char *argv[])
{
  if(argc != 3) {
	  printf("Error args\n");
	  return -1;
  }
  int sfd;
  sfd = socket(AF_INET, SOCK_DGRAM, 0);
  if(sfd == -1) {
	  perror("Failure\n");
	  return -1;
  }

  struct sockaddr_in  server;
  bzero(&server, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_port = htons(atoi(argv[2]));
  server.sin_addr.s_addr = inet_addr(argv[1]);
  char buf[128] = "hello";
//  char *ptr = "What the fuck";
  int res = sendto(sfd, buf, strlen(buf), 0, (struct sockaddr *)&server, sizeof(struct sockaddr));
  if( res == -1){
	  printf("connect\n");
	  return -1;
  }

	 struct sockaddr_in client;
	 bzero(&client, sizeof(client));
	 int new_fd;
	 int len = sizeof(client);
     bzero(buf, sizeof(buf));
	 printf("This\n");
	 new_fd = recvfrom(sfd, buf, sizeof(buf), 0, (struct sockaddr *)&client, &len);
     if(new_fd == -1){
		 printf("recv\n");
		 return -1;
	 }
  	 printf("%s\n",buf);
  	 printf("new_fd:%d, ip=%s, port=%d\n", new_fd, inet_ntoa(client.sin_addr), ntohs(client.sin_port));
 
  printf("%d End\n",res);

  close(sfd);
  return 0;
}
