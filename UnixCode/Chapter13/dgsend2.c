/*************************************************************************
    > File Name: dgsend.c
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月18日 星期三 11时24分58秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>

#define oops(m,x){perror(m);exit(x);}

int make_dgram_client_socket();
int make_internet_address(char*,int,struct sockaddr_in*);

int main(int ac,char *av[]){
	int sock;
	char *msg;
	char buf[BUFSIZ];
	struct sockaddr_in saddr;
	socklen_t saddrlen;
	if(ac!=4){
		fprintf(stderr,"usage:dgsend host port 'message'\n");
		exit(1);
	}
	msg = av[3];
	if((sock=make_dgram_client_socket())==-1) oops("cannot make socket",2);
	make_internet_address(av[1],atoi(av[2]),&saddr);
	if(sendto(sock,msg,strlen(msg),0,&saddr,sizeof(saddr))==-1) oops("sendto failed",3);
	saddrlen = sizeof(saddr);
	int msglen = recvfrom(sock,buf,BUFSIZ,0,&saddr,&saddrlen);
	if(msglen<=0) 
		printf("receive msg err");
	else{
		buf[msglen]='\0';
		printf("receive msg from server:%s\n",buf);
	}
	return 0;
}

