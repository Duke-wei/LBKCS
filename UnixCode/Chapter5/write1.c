/*************************************************************************
    > File Name: write1.c
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月09日 星期一 10时41分45秒
 ************************************************************************/

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main(int ac,char* av[]){
	int fd;
	char buf[BUFSIZ];
	char rebuf[BUFSIZ];
	if(ac!=3){
		fprintf(stderr,"usage: write0 yourID ttyname\n");
		exit(1);
	}
	fd = open(av[2],O_WRONLY);
	if(fd==-1){
		perror(av[2]);
		exit(1);
	}
	strncpy(rebuf,av[1],strlen(av[1]));
	while(fgets(buf,BUFSIZ,stdin)!=NULL){
		strncpy(rebuf,av[1],strlen(av[1]));
		strncat(rebuf,buf,strlen(buf));
		if(write(fd,rebuf,strlen(rebuf))==-1)
			break;
	}
	close(fd);
}
