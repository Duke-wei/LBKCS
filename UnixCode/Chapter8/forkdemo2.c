/*************************************************************************
    > File Name: forkdemo1.c
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月13日 星期五 12时38分58秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	printf("My pid is %d\n",getpid());
	fork();
	fork();
	fork();
	printf("my pid is%d\n",getpid());
	return 0;
}
