/*************************************************************************
    > File Name: hello_single.c
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月19日 星期四 12时03分28秒
 ************************************************************************/

#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#define NUM 5

void* print_msg(char * msg){
	for(int i=0;i<NUM;++i){
		printf("%s",msg);
		fflush(stdout);
		sleep(1);
	}
	return NULL;
}

int main(){
	pthread_t t1,t2;
	pthread_create(&t1,NULL,print_msg,(void*)"hello");
	pthread_create(&t2,NULL,print_msg,(void*)"world\n");
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
}
