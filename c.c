#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>

#define MAX 60

int main(){
//socket()
int sockfd=socket(AF_INET,SOCK_STREAM,0);

//connect()
struct sockaddr_in serv_addr;
serv_addr.sin_family=AF_INET;
serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
serv_addr.sin_port=htons(5035);
connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));

//write()
char rem[MAX];
printf("Enter the name of the file: ");
scanf("%s",rem);
write(sockfd,rem,MAX);

//read()
char recvline[MAX];
while(read(sockfd,recvline,MAX)!=0){
printf("%s",recvline);
}

//rem code
close(sockfd);
return 0;

}







