/*************************************************************************
    > File Name: incrprint.c
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月19日 星期四 13时21分43秒
 ************************************************************************/

#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

#define NUM 5
int counter = 0;

void *print_count(void *m){
	for(int i=0;i<NUM;++i){
		printf("count=%d\n",counter);
		sleep(1);
	}
	return NULL;
}

int main(){
	pthread_t t1;
	int i;
	pthread_create(&t1,NULL,print_count,NULL);
	for(i=0;i<NUM;++i){
		counter++;
		sleep(1);
	}
	pthread_join(t1,NULL);
}
