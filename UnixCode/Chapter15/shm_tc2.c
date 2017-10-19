/*************************************************************************
    > File Name: shm_ts2.c
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月19日 星期四 19时58分40秒
 ************************************************************************/

#include<stdio.h>
#include<sys/shm.h>
#include<time.h>
#include<sys/types.h>
#include<sys/sem.h>
#include<signal.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#define TIME_MEM_KEY 99
#define IME_SEM_KEY 9900
#define SEG_SIZE ((size_t)100)
#define oops(m,x) {perror(m);exit(x);}

union semun{
	int val;
	struct semid_ds *buf;
	ushort *array;
};
int seg_id,semset_id;

void cleanup(int n){
	shmctl(seg_id,IPC_RMID,NULL);
	semctl(semset_id,0,IPC_RMID,NULL);
}

void set_sem_value(int semset_id,int semnum,int val){
	union semun initval;
	initval.val = val;
	if(semctl(semset_id,semnum,SETVAL,initval)==-1) oops("semstl",4);
}

void wait_and_lock(int semset_id){
	struct sembuf actions[2];
	actions[0].sem_num = 0;
	actions[0].sem_flg = SEM_UNDO;
	actions[0].sem_op = 0;

	actions[1].sem_num = 1;
	actions[1].sem_flg = SEM_UNDO;
	actions[1].sem_op = +1;

	if(semop(semset_id,actions,2)==-1) oops("semop:locking",10);
}

void release_lock(int semset_id){
	struct sembuf actions[1];
	actions[0].sem_num = 1;
	actions[0].sem_flg = SEM_UNDO;
	actions[0].sem_op = -1;
	if(semop(semset_id,actions,1)==-1) oops("semop:unlocking",10);
}

int main(){
	int seg_id,semset_id;
	char *mem_ptr;
	seg_id = shmget(TIME_MEM_KEY,SEG_SIZE,IPC_CREAT|0777);
	if(seg_id==-1) oops("shmget",1);
	mem_ptr = (char*)shmat(seg_id,NULL,0);
	if(mem_ptr==(void*)-1) oops("shmat",2);
	semset_id = semget(TIME_MEM_KEY,2,0);
	wait_and_lock(semset_id);
	printf("The time,direct from memory:..%s",mem_ptr);
	release_lock(semset_id);
	shmdt(mem_ptr);
	return 0;
}
