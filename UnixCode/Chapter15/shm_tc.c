/*************************************************************************
    > File Name: shm_tc.c
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月19日 星期四 19时19分22秒
 ************************************************************************/

#include<stdio.h>
#include<sys/shm.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#define TIME_MEM_KEY 99
#define SEG_SIZE ((size_t)100)
#define oops(m,x) { perror(m);exit(x); }

int main(){
	int seg_id;
	char *mem_ptr;
	seg_id = shmget(TIME_MEM_KEY,SEG_SIZE,0777);
	if(seg_id==-1) oops("shmget",1);
	mem_ptr = (char*)shmat(seg_id,NULL,0);
	if(mem_ptr==(void*)-1) oops("shmat",2);
	printf("The time,direct from memory:..%s",mem_ptr);
	shmdt(mem_ptr);
	return 0;
}
