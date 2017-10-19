/*************************************************************************
    > File Name: hello1.c
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月11日 星期三 09时36分30秒
 ************************************************************************/

#include<stdio.h>
#include<curses.h>
int main(){
	initscr();
	clear();
	move(10,20);
	addstr("Hello,world");
	move(LINES-1,0);
	refresh();
	getch();
	endwin();
	return 0;
}
