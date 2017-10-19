/*************************************************************************
    > File Name: stdinredir1.c
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月15日 星期日 10时37分40秒
 ************************************************************************/

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	int fd;
	char line[100];
	fgets(line,100,stdin);printf("%s",line);
	fgets(line,100,stdin);printf("%s",line);
	fgets(line,100,stdin);printf("%s",line);
	close(0);
	fd = open("/etc/passwd",O_RDONLY);
	if(fd!=0){
		fprintf(stderr,"Could not open data as fd 0\n");
		exit(1);
	}
	fgets(line,100,stdin);printf("%s",line);
	fgets(line,100,stdin);printf("%s",line);
	fgets(line,100,stdin);printf("%s",line);
	close(fd);
	return 0;
}
