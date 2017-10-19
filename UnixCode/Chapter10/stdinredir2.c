/*************************************************************************
    > File Name: stdinredir2.c
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月15日 星期日 10时47分35秒
 ************************************************************************/

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#define CLOSE_DUP
#define USE_DUP2
int main(){
	int fd;
	int newfd;
	char line[100];
	fgets(line,100,stdin);printf("%s",line);
	fgets(line,100,stdin);printf("%s",line);
	fgets(line,100,stdin);printf("%s",line);
	fd = open("data",O_RDONLY);
#ifdef CLOSE_DUP
	close(0);
	newfd = dup(fd);
#else
	newfd = dup2(fd,0);
#endif
	if(newfd!=0){
		fprintf(stderr,"Could not duplicate fd to 0\n");
		exit(1);
	}
	close(fd);
	fgets(line,100,stdin);printf("%s",line);
	fgets(line,100,stdin);printf("%s",line);
	fgets(line,100,stdin);printf("%s",line);
	return 0;
}
