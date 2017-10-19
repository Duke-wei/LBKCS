/*************************************************************************
    > File Name: exec1.c
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月13日 星期五 10时40分03秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>

int main(){
	char* arglist[3];
	arglist[0]="ls";
	arglist[1]="-l";
	arglist[2]=0;
	printf("*** About to exec ls -l\n");
	execvp("ls",arglist);
	printf("*** ls is done.bye\n");
	return 0;
}
