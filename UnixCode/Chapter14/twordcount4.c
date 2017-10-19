/*************************************************************************
    > File Name: twordcount1.c
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月19日 星期四 13时30分49秒
 ************************************************************************/

#include<stdio.h>
#include<pthread.h>
#include<ctype.h>
#include<stdlib.h>

struct arg_set{
	char *fname;
	int count;
};
struct arg_set *mailbox;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t flag = PTHREAD_COND_INITIALIZER;

void* count_words(void* a){
	struct arg_set *args = (struct arg_set*)a;
	FILE *fp;
	int c,prevc = '\0';
	if((fp=fopen(args->fname,"r"))!=NULL){
		while((c=getc(fp))!=EOF){
			if(!isalnum(c)&&isalnum(prevc)){
				args->count++;
			}
			prevc = c;
		}
		fclose(fp);
	}else{
		perror(args->fname);
	}
	printf("COUNT:waiting to get lock\n");
	pthread_mutex_lock(&lock);
	printf("COUNT:have lock,storing data\n");
	//pthread_cond_wait 使线程挂起直到另一个线程通过条件变量发生消息
	//该函数总是和互斥锁一起使用
	//首先自动释放指定的锁，然后等待条件变量的变化
	//调用此函数之前，必须上锁
	if(mailbox!=NULL) pthread_cond_wait(&flag,&lock);
	mailbox = args;
	printf("COUNT: raising flag\n");
	pthread_cond_signal(&flag);
	printf("COUNT: unlocking box\n");
	pthread_mutex_unlock(&lock);
	return NULL;
}

int main(int ac,char *av[]){
	pthread_t t1,t2;
	struct arg_set args1,args2;
	int reports_in = 0;
	int total_words = 0;
	if(ac!=3){
		printf("usage: %s file1 file2\n",av[0]);
		exit(1);
	}
	pthread_mutex_lock(&lock);
	args1.fname = av[1];
	args1.count = 0;
	pthread_create(&t1,NULL,count_words,(void*)&args1);
	args2.fname = av[2];
	args2.count = 0;
	pthread_create(&t2,NULL,count_words,(void*)&args2);
	while(reports_in<2){
		printf("MAIN: waiting for flag to go up\n");
		pthread_cond_wait(&flag,&lock);
		printf("MAIN: Wow! flag was raised, I have the lock\n");
		printf("%7d: %s\n",mailbox->count,mailbox->fname);
		total_words += mailbox->count;
		if(mailbox==&args1) 
			pthread_join(t1,NULL);
		if(mailbox==&args2)
			pthread_join(t2,NULL);
		mailbox = NULL;
		pthread_cond_signal(&flag);
		reports_in++;
	}
	printf("%5d:total words\n",total_words);
	return 0;
}
