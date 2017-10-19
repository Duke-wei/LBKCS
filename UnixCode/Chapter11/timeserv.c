/*************************************************************************
    > File Name: timeserv.c
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月16日 星期一 14时51分43秒
 ************************************************************************/

#include "mylinux.h"
#define PORTNUM 13000
#define HOSTLEN 256

int main(int ac,char *av[]){
	struct sockaddr_in saddr;
	struct hostent *hp;
	char hostname[HOSTLEN];
	int sock_id,sock_fd;
	FILE *sock_fp;
	time_t thetime;
	sock_id = socket(PF_INET,SOCK_STREAM,0);
	if(sock_id==-1) oops("socket",1);
	bzero((void*)&saddr,sizeof(saddr));
	gethostname(hostname,HOSTLEN);
	hp = gethostbyname(hostname);
	bcopy((void*)hp->h_addr,(void*)&saddr.sin_addr,hp->h_length);
	saddr.sin_port = htons(PORTNUM);
	saddr.sin_family = AF_INET;
	if(bind(sock_id,(struct sockaddr*)&saddr,sizeof(saddr))!=0) oops("bind",1);
	if(listen(sock_id,1)!=0) oops("listen",1);
	while(1){
		sock_fd = accept(sock_id,NULL,NULL);
		printf("Wow!got a call!\n");
		if(sock_fd==-1) oops("accept",1);
		sock_fp = fdopen(sock_fd,"w");
		if(sock_fp==NULL) oops("fdopen",1);
		thetime = time(NULL);
		fprintf(sock_fp,"the time here is ..");
		fprintf(sock_fp,"%s",ctime(&thetime));
		fclose(sock_fp);
	}
	return 0;
}

