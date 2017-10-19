/*************************************************************************
    > File Name: hello1.c
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月11日 星期三 09时36分30秒
 ************************************************************************/

#include<stdio.h>
#include<curses.h>
#include<unistd.h>
int main(){
	initscr();
	clear();
	for(int i=0;i<LINES;++i){
		move(i,i+i);
		if(i%2==1) standout();
		addstr("Hello,world");
		if(i%2==1) standend();
		sleep(1);
		refresh();
	}
	endwin();
	return 0;
}
