/*************************************************************************
    > File Name: waitdemo1.c
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月13日 星期五 13时09分11秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

#define DELAY 2
void child_code(int);
void parent_code(int);
int main(){
	int newpid;
	printf("before: mypid is %d\n",getpid());
	if((newpid=fork())==-1) perror("fork");
	else if(newpid==0) child_code(DELAY);
	else parent_code(newpid);
}

void child_code(int delay){
	printf("child %d here.will sleep for %d seconds\n",getpid(),delay);
	sleep(delay);
	printf("child done.about to exit\n");
	exit(17);
}

void parent_code(int childpid){
	int wait_rv;
	wait_rv = wait(NULL);
	printf("done waiting for %d.Wait returned:%d\n",childpid,wait_rv);
}
