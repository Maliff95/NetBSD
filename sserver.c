#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>

int main(){
  int cSocket,nSocket,sSocket;
  char message[1024];
  struct sockaddr_in serverAddr;
  struct sockaddr_storage serverStorage;
  socklen_t addr_size;

  sSocket = socket(PF_INET, SOCK_STREAM, 0);

  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(5549);
  serverAddr.sin_addr.s_addr = inet_addr("192.168.44.129");
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

  bind(sSocket, (struct sockaddr *) &serverAddr,
  sizeof(serverAddr));

  if(listen(sSocket,5)==0)
    printf("Listening-----\n");
  else
    printf("Error\n");

  addr_size =sizeof serverStorage;
  nSocket = accept(sSocket, (struct sockaddr *) &serverStorage,
  &addr_size);

  puts("---connection Establish---");

  recv(nSocket, message , 50 , 0);
  char s[]="Assalamualaikum";
  char a[50];
  strcpy(a,message);
  if(strcasecmp(a ,s)==0)
  {
	strcpy(message, "Waalaikumusalam");
  }
  else
  {
	strcpy(message, "Are you Muslim?\n");
  }
  send(nSocket,message, 50, 0);
  return 0;
}
