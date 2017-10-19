/*************************************************************************
    > File Name: shm_ts.c
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月19日 星期四 19时14分40秒
 ************************************************************************/

#include<stdio.h>
#include<sys/shm.h>
#include<time.h>
#include<unistd.h>
#include<string.h> 
#include<stdlib.h>
#define TIME_MEM_KEY 99
#define SEG_SIZE ((size_t)100)
#define oops(m,x) {perror(m);exit(x);}

int main(){
	int seg_id;
	char *mem_ptr;
	long now;
	int n;
	seg_id = shmget(TIME_MEM_KEY,SEG_SIZE,IPC_CREAT|0777);
	if(seg_id==-1) oops("shmget",1);
	mem_ptr = (char*)shmat(seg_id,NULL,0);
	if(mem_ptr==(void*)-1){
		oops("shmat",2);
	}
	for(n=0;n<60;++n){
		time(&now);
		strcpy(mem_ptr,ctime(&now));
		sleep(1);
	}
	shmctl(seg_id,IPC_RMID,NULL);
	return 0;
}
