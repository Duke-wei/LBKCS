/*************************************************************************
    > File Name: lclnt1.c
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月18日 星期三 13时47分59秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>

void do_regular_work(){
	printf("SuperSleep version 1.0 Running-Licensed Software\n");
	sleep(5);
}

int main(int ac,char *av[]){
	setup();
	if(get_ticket()!=0) exit(0);
	do_regular_work();
	release_ticket();
	shut_down();
	return 0;
}
