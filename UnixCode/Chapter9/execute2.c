/*************************************************************************
    > File Name: execute.c
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月14日 星期六 09时46分57秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>
#include "varlib.h"

int execute(char* argv[]){
	extern char **environ;
	int pid;
	int child_info = -1;
	if(argv[0]==NULL) return 0;
	if((pid=fork())==-1) perror("fork");
	else if(pid==0){
		environ = VLtable2environ();
		signal(SIGINT,SIG_DFL);
		signal(SIGQUIT,SIG_DFL);
		execvp(argv[0],argv);
		perror("cannot execute command");
		exit(1);
	}else{
		if(wait(&child_info)==-1) perror("wait");
		return child_info;
	}
	return 0;
}
