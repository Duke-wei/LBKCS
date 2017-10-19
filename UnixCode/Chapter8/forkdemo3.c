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
	int fork_rv;
	printf("Before:my pid is %d\n",getpid());
	fork_rv = fork();
	if(fork_rv==-1) perror("fork");
	else if(fork_rv==0) printf("I am the child.my pid = %d\n",getpid());
	else printf("I am the parent.my child is %d\n",fork_rv);
	return 0;
}
