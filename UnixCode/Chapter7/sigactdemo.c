/*************************************************************************
    > File Name: sigactdemo.c
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月11日 星期三 12时35分47秒
 ************************************************************************/

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#define INPUTLEN 100

int main(){
	struct sigaction newhandler;
	sigset_t blocked;
	void inthandler(int);
	char x[INPUTLEN];
	newhandler.sa_handler = inthandler;
	newhandler.sa_flags = SA_RESETHAND|SA_RESTART;
	sigemptyset(&blocked);
	sigaddset(&blocked,SIGQUIT);
	newhandler.sa_mask = blocked;
	if(sigaction(SIGQUIT,&newhandler,NULL)==-1)
		perror("sigaction");
	else{
		while(1){
			fgets(x,INPUTLEN,stdin);
			printf("input:%s",x);
		}
	}
	return 0;
}

void inthandler(int s){
	printf("Called with signal %d\n",s);
	sleep(2);
	printf("done handling signal %d\n",s);
}
