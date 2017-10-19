/*************************************************************************
    > File Name: bounce_aio.c
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月11日 星期三 16时24分17秒
 ************************************************************************/
/*
 * 同步阻塞I/O:用户进程进行I/O操作，一直阻塞到I/O操作完成为止。 
 * 同步非阻塞I/O:用户程序可以通过设置文件描述符的属性O_NONBLOCK，I/O操作可以立即返回，但是并不保证I/O操作成功。 
 * 异步事件阻塞I/O:用户进程可以对I/O事件进行阻塞，但是I/O操作并不阻塞。通过select/poll/epoll等函数调用来达到此目的。
 * 异步时间非阻塞I/O:也叫做异步I/O(AIO)，用户程序可以通过向发送I/O请求命令，不用带I/O事件真正发生，可以继续左另外的事情，等I/O操作完成，内核会通过函数回调或者信号机制通知进程。提高系统吞吐量。
 */
#include<stdio.h>
#include<curses.h>
#include<signal.h>
#include<sys/time.h>
#include<aio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

#define MESSAGE "hello"
#define BLANK "     "

int row = 10;
int col = 0;
int dir = 1;
int delay = 200;
int done = 0;

struct aiocb kbcbuf;

void on_input(int signum){
	int c;
	char *cp = (char*)kbcbuf.aio_buf;
	if(aio_error(&kbcbuf)!=0) perror("reading failed");
	else {
		if(aio_return(&kbcbuf)==1){
			c = *cp;
			if(c=='Q'||c==EOF) done=1;
			else if(c==' ') dir = -dir;
		}
	}
	aio_read(&kbcbuf);
}

void on_alarm(int signum){
	signal(SIGALRM,on_alarm);
	mvaddstr(row,col,BLANK);
	col += dir;
	mvaddstr(row,col,MESSAGE);
	refresh();
	if(dir==-1&&col<=0) dir=1;
	else if(dir==1&&(col+strlen(MESSAGE))>=COLS) dir=-1;
}

void setup_aio_buffer(){
	static char input[1];
	kbcbuf.aio_fildes = 0;
	kbcbuf.aio_buf = input;
	kbcbuf.aio_nbytes = 1;
	kbcbuf.aio_offset = 0;
	kbcbuf.aio_sigevent.sigev_notify = SIGEV_SIGNAL;
	kbcbuf.aio_sigevent.sigev_signo = SIGIO;
}

int set_ticker(int n){
	struct itimerval new_timeset;
	long n_sec,n_usecs;
	n_sec = n/1000;
	n_usecs = (n%1000)*1000L;
	new_timeset.it_interval.tv_sec = n_sec;
	new_timeset.it_interval.tv_usec = n_usecs;
	new_timeset.it_value.tv_sec = n_sec;
	new_timeset.it_value.tv_usec = n_usecs;
	return setitimer(ITIMER_REAL,&new_timeset,NULL);
}

int main(){
	initscr();
	crmode();
	noecho();
	clear();
	signal(SIGIO,on_input);
	setup_aio_buffer();
	aio_read(&kbcbuf);
	signal(SIGALRM,on_alarm);
	set_ticker(delay);
	mvaddstr(row,col,MESSAGE);
	while(!done) pause();
	endwin();
}

