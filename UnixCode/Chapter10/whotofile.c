/*************************************************************************
    > File Name: whotofile.c
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月15日 星期日 11时51分02秒
 ************************************************************************/
//标准输入、输出以及错误输出分别对应文件描述符0,1,2
//内核总是使用最低可用文件描述符
//文件描述符集合通过exec调用传递，且不会被改变
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
int main(){
	int pid;
	int fd;
	printf("About to run who into a file\n");
	if((pid=fork())==-1){
		perror("fork");
		exit(1);
	}
	if(pid==0){
		close(1);
		fd = creat("userlist",0644);
		execlp("who","who",NULL);
		perror("execlp");
		exit(1);
	}
	if(pid!=0){
		wait(NULL);
		printf("Done running who.results in userlist\n");
	}
	return 0;
}
