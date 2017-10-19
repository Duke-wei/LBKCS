/*************************************************************************
    > File Name: hello1.c
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月11日 星期三 09时36分30秒
 ************************************************************************/

#include<stdio.h>
#include<curses.h>
#include<unistd.h>

#define LEFTEDGE 10
#define RIGHTEDGE 30
#define ROW 10

int main(){
	char message[] = "Hello";
	char blank[] = "     ";
	int dir = +5;
	int pos = LEFTEDGE;
	initscr();
	clear();
	while(1){
		move(ROW,pos);
		addstr(message);
		move(LINES-1,COLS-1);
		refresh();
		sleep(1);
		move(ROW,pos);
		addstr(blank);
		pos += dir;
		if(pos>=RIGHTEDGE) dir = -7;
		if(pos<=LEFTEDGE) dir = +7;
	}
	endwin();
	return 0;
}
