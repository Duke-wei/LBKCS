/*************************************************************************
    > File Name: bounce1d.c
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月19日 星期四 15时04分13秒
 ************************************************************************/

#include<stdio.h>
#include<curses.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#define MESSAGE "HELLO"

int row;
int col;
int dir;
int delay;

void* moving_msg(char* msg){
	while(1){
		usleep(delay*1000);
		move(row,col);
		addstr(msg);
		refresh();
		col += dir;
		if(col<=0&&dir==-1) dir=1;
		else if(col+(int)strlen(msg)>=COLS&&dir==1) dir=-1;
	}
}

int main(){
	int ndelay;
	int c;
	pthread_t msg_thread;
	initscr();
	crmode();
	noecho();
	clear();
	row = 10;
	col = 0;
	dir = 1;
	delay = 200;
	if(pthread_create(&msg_thread,NULL,moving_msg,MESSAGE)){
		fprintf(stderr,"error creating thread");
		endwin();
		exit(0);
	}
	while(1){
		ndelay = 0;
		c = getch();
		if(c=='Q') break;
		if(c==' ') dir = ~dir;
		if(c=='f'&&delay>2) ndelay = delay/2;
		if(c=='s') ndelay = delay*2;
		if(ndelay>0) delay = ndelay;
	}
	pthread_cancel(msg_thread);
	endwin();
}
