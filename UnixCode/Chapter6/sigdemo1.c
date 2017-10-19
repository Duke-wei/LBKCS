/*************************************************************************
    > File Name: sigdemo1.c
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月10日 星期二 14时52分15秒
 ************************************************************************/

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
int main(){
	void f(int);
	signal(SIGINT,f);
	for(int i=0;i<5;++i){
		printf("hello\n");
		sleep(1);
	}
	return 0;
}

void f(int signum){
	printf("OUCH! \n");
}
