// server
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
FILE *f1;
char buff[4096];


int main(){
//socket()
int sockfd=socket(AF_INET,SOCK_STREAM,0);

//bind()
struct sockaddr_in serv_addr;
serv_addr.sin_family=AF_INET;
serv_addr.sin_addr.s_addr=INADDR_ANY;
serv_addr.sin_port=htons(5035);
printf("\nBinded");
bind(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));

//listen()
printf("\nListening");
listen(sockfd,5);

//accept()
struct sockaddr_in cli_addr;
int clength=sizeof(cli_addr);
int newsockfd=accept(sockfd,(struct sockaddr*)&cli_addr,&clength);

//read()
char str[MAX];
close(sockfd);
read(newsockfd,&str,MAX);
printf("Client message recieved\n File name: %s",str);

//write()
f1=fopen(str,"r");
while(fgets(buff,4096,f1)!=NULL){
write(newsockfd,buff,MAX);
printf("\n");
}

//rem code
fclose(f1);
printf("\nFile transferred\n");
return 0; 
}
