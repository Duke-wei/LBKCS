/*************************************************************************
    > File Name: bounce_async.c
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月11日 星期三 15时56分49秒
 ************************************************************************/

#include<stdio.h>
#include<curses.h>
#include<signal.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/time.h>
#include<string.h>

#define MESSAGE "hello"
#define BLANK "     "

int row = 10;
int col = 0;
int dir = 1;
int delay = 200;
int done = 0;

void on_input(int signum){
	int c = getch();
	if(c=='Q'||c==EOF) done=1;
	else if(c==' ') dir = -dir;
}

void on_alarm(int signum){
	signal(SIGALRM,on_alarm);
	mvaddstr(row,col,BLANK);
	col += dir;
	mvaddstr(row,col,MESSAGE);
	refresh();
	if(dir==-1&&col<=0) dir = 1;
	else if(dir==1&&(col+strlen(MESSAGE))>=COLS) dir = -1;
}

void enable_kbd_signals(){
	int fd_flags;
	fcntl(0,F_SETOWN,getpid());
	fd_flags = fcntl(0,F_GETFL);
	fcntl(0,F_SETFL,(fd_flags|O_ASYNC));
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
	void on_alarm(int);
	void on_input(int);
	void enable_kbd_signals();
	initscr();
	crmode();
	noecho();
	clear();
	signal(SIGIO,on_input);
	enable_kbd_signals();
	signal(SIGALRM,on_alarm);
	set_ticker(delay);
	move(row,col);
	addstr(MESSAGE);
	while(!done){
		pause();
	}
	endwin();
}
