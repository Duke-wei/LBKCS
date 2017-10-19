/*************************************************************************
    > File Name: sleep1.c
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月11日 星期三 10时11分53秒
 ************************************************************************/

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
//#define SHHHH
int main(){
	void wakeup(int);
	printf("about to sleep for 4 second\n");
	signal(SIGALRM,wakeup);
	alarm(4);
	pause(); //挂起进程
	printf("Morning so soon?\n");
}

void wakeup(int signum){
#ifndef SHHHH
	printf("Alarm received from kernel\n");
#endif
}
