/*************************************************************************
    > File Name: pipedemo.c
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月15日 星期日 12时12分06秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

#define oops(m,x) { perror(m); exit(x); }

int main(int ac,char** av){
	int pipefd[2];
	int pid;
	if(ac!=3){
		fprintf(stderr,"usage:pipe cmd1 cmd2\n");
		exit(1);
	}
	if(pipe(pipefd)==-1){
		oops("cannot get a pipe",1);
	}
	if((pid=fork())==-1){
		oops("Cannot fork",2);
	}
	if(pid>0){
		close(pipefd[1]);
		if(dup2(pipefd[0],0)==-1) oops("could not redirect stdin",3);
		close(pipefd[0]);
		execlp(av[2],av[2],NULL);
		oops(av[2],4);
	}else{
		close(pipefd[0]);
		//将管道写入的一端连接到stdout
		if(dup2(pipefd[1],1)==-1) oops("could not redirect stdout",4);
		close(pipefd[1]);
		execlp(av[1],av[1],NULL);
		oops(av[1],5);
	}
	return 0;
}
