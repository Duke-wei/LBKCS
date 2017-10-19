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

#define CHILD_MESS "I want a cookie\n"
#define PAR_MESS "testing..\n"
#define oops(m,x) { perror(m); exit(x); }

int main(){
	int pipefd[2];
	int len;
	char buf[BUFSIZ];
	int read_len;
	if(pipe(pipefd)==-1){
		oops("cannot get a pipe",1);
	}
	switch(fork()){
		case -1:
			oops("cannot fork",2);
		case 0:
			len = strlen(CHILD_MESS);
			while(1){
				if(write(pipefd[1],CHILD_MESS,len)!=len) oops("write",3);
				sleep(5);
			}
		default:
			len = strlen(PAR_MESS);
			while(1){
				if(write(pipefd[1],PAR_MESS,len)!=len) oops("write",4);
				sleep(1);
				read_len = read(pipefd[0],buf,BUFSIZ);
				if(read_len<=0) break;
				write(1,buf,read_len);
			}
	}
	return 0;
}
