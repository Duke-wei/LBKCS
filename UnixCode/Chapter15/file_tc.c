/*************************************************************************
    > File Name: file_tc.c
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月19日 星期四 19时51分21秒
 ************************************************************************/

#include<stdio.h>
#include<sys/file.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

#define oops(m,x) {perror(m);exit(x);}
#define BUFLEN 10

void lock_operation(int fd,int op){
	struct flock lock;
	lock.l_whence = SEEK_SET;
	lock.l_start = lock.l_len = 0;
	lock.l_pid = getpid();
	lock.l_type = op;
	if(fcntl(fd,F_SETLKW,&lock)==-1) oops("lock operation",6);
}

int main(int ac,char *av[]){
	int fd,nread;
	char buf[BUFSIZ];
	if(ac!=2){
		fprintf(stderr,"usage:file_tc filename\n");
		exit(1);
	}
	if((fd=open(av[1],O_RDONLY))==-1) oops(av[1],3);
	lock_operation(fd,F_RDLCK);
	while((nread=read(fd,buf,BUFSIZ))>0) write(1,buf,nread);
	lock_operation(fd,F_UNLCK);
	close(fd);
}
