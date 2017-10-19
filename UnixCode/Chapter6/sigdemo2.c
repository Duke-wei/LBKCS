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
	signal(SIGINT,SIG_IGN);
	printf("you can't stop me!\n");
	while(1){
		sleep(1);
		printf("hello\n");
	}
	return 0;
}
