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
	int ret_from_fork,mypid;
	mypid = getpid();
	printf("Before:my pid is %d\n",mypid);
	ret_from_fork = fork();
	sleep(1);
	printf("After:my pid is %d,fork() said %d\n",getpid(),ret_from_fork);
	return 0;
}
