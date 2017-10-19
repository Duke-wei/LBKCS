/*************************************************************************
    > File Name: server0.c
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月17日 星期二 10时06分13秒
 ************************************************************************/

#include "socklib.h"
void process_request(int fd){
	int pid = fork();
	switch(pid){
		case -1:return;
		case 0: dup2(fd,1);
				close(fd);
				execl("/bin/date","date",NULL);
				oops("execlp");
		default:wait(NULL);
	}
}
int main(int ac,char *av[]){
	int sock,fd;
	if(ac<2) printf("usage:./server port");
	sock = make_server_socket(atoi(av[1]));
	if(sock==-1) exit(1);
	while(1){
		fd = accept(sock,NULL,NULL);
		if(fd==-1) break;
		process_request(fd);
		close(fd);
	}
	return 0;
}
