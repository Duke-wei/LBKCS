/*************************************************************************
    > File Name: who01.c
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月06日 星期五 12时33分24秒
 ************************************************************************/

#include<stdio.h>
#include<utmp.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>

#define SHOWHOST

void showtime(long t){
	char* cp = ctime(&t);
	printf("%16.16s",cp);
}

void show_info(struct utmp* fp){
	if(fp->ut_type!=USER_PROCESS) return ;
	printf("%-8.8s",fp->ut_name);
	printf(" ");
	printf("%-8.8s",fp->ut_line);
	printf(" ");
	showtime(fp->ut_time);
//	printf("%10d",fp->ut_time);
	printf(" ");
#ifdef SHOWHOST
	if(fp->ut_host[0]!='\0')
		printf("(%s)",fp->ut_host);
#endif
	printf("\n");
}

int main(){
	struct utmp cr;
	int utmpfd;
	int reclen = sizeof(struct utmp);
	if((utmpfd = open(UTMP_FILE,O_RDONLY))==-1){
		perror(UTMP_FILE);
		exit(1);
	}
	while(read(utmpfd,&cr,reclen)==reclen)
		show_info(&cr);
	close(utmpfd);
	return 0;
}
