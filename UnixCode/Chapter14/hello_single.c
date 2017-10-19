/*************************************************************************
    > File Name: hello_single.c
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月19日 星期四 12时03分28秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#define NUM 5

void print_msg(char * msg){
	for(int i=0;i<NUM;++i){
		printf("%s",msg);
		fflush(stdout);
		sleep(1);
	}
}

int main(){
	print_msg("hello");
	print_msg("world\n");
}
