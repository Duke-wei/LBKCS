/*************************************************************************
    > File Name: client0.c
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月17日 星期二 10时05分02秒
 ************************************************************************/

#include "socklib.h"

void takl_with_server(int fd){
	char buf[BUFSIZ];
	int n;
	n = read(fd,buf,BUFSIZ);
	write(1,buf,n);
}
int main(int ac,char *av[]){
	int fd;
	if(ac<=2){
		printf("usage:./client host port\n");
	}
	fd = connect_to_server(av[1],atoi(av[2]));
	if(fd==-1) exit(1);
	takl_with_server(fd);
	close(fd);
	return 0;
}
