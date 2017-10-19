/*************************************************************************
    > File Name: psh1.c
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月13日 星期五 10时54分49秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>
#include<stdlib.h>

#define MAXARGS 20
#define ARGLEN 100
//这个程序会运行完退出，由于执行execupy会直接替换当前进程的指令和数据，所以跑完就over了

int execute(char* arglist[]);
char *makestring(char*);

int main(){
	char *arglist[MAXARGS+1];
	int numargs;
	char argbuf[ARGLEN];
	numargs = 0;
	while(numargs<MAXARGS){
		printf("Arg[%d]?",numargs);
		if(fgets(argbuf,ARGLEN,stdin)&&*argbuf!='\n')
			arglist[numargs++] = makestring(argbuf);
		else{
			if(numargs>0){
				arglist[numargs]=NULL;
				execute(arglist);
				numargs = 0;
			}
		}
	}
	return 0;
}

int execute(char* arglist[]){
	execvp(arglist[0],arglist);
	perror("execvp failed");
	exit(1);
}

char* makestring(char* buf){
	char* cp;
	//替换结尾\n
	buf[strlen(buf)-1]='\0';
	cp = (char*)malloc(strlen(buf)+1);
	if(cp==NULL){
		fprintf(stderr,"no memory\n");
		exit(1);
	}
	strcpy(cp,buf);
	return cp;
}
