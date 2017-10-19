/*************************************************************************
    > File Name: logfilec.c
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月19日 星期四 11时49分16秒
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/un.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#define SOCKET "/tmp/logfilesock"
#define oops(m,x) {perror(m);exit(x);}

int main(int ac,char *av[]){
	int sock;
	struct sockaddr_un addr;
	socklen_t addrlen;
	char sockname[]=SOCKET;
	char *msg = av[1];
	if(ac!=2){
		fprintf(stderr,"usage:logfilec 'message'\n");
		exit(1);
	}
	sock = socket(PF_UNIX,SOCK_DGRAM,0);
	if(sock==-1) oops("socket",2);
	addr.sun_family = AF_UNIX;
	strcpy(addr.sun_path,sockname);
	addrlen = strlen(sockname)+sizeof(addr.sun_family);
	if(sendto(sock,msg,strlen(msg),0,&addr,addrlen)==-1) oops("sendto",3);
	return 0;
}
