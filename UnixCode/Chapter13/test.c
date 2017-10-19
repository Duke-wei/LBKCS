/*************************************************************************
    > File Name: dgram.c
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月18日 星期三 12时21分59秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<string.h>

#define HOSTLEN 256


int make_internet_address(char* hostname){
	struct hostent *hp;
	hp = gethostbyname(hostname);
	if(hp==NULL) return -1;
	printf("hp->name:%s\n",hp->h_name);
	return 0;
}

int make_dgram_server_socket(){
	char hostname[HOSTLEN];
	gethostname(hostname,HOSTLEN);
	printf("hostname :%s\n",hostname);
	make_internet_address(hostname);
	return 0;
}

int main(){
	make_dgram_server_socket();
	return 0;
}


