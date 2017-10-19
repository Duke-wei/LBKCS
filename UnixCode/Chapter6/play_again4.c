/*************************************************************************
    > File Name: play_again.c
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月10日 星期二 12时44分59秒
 ************************************************************************/

#include<stdio.h>
#include<termios.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<ctype.h>
#include<signal.h>
#include<stdlib.h>

#define ASK "Do you want another transaction"
#define TRIES 3
#define SLEEPTIME 2
#define BEEP putchar('\a')

int get_reponse(char*,int);
char get_ok_char();
void set_cr_noecho_mode();
void set_nodelay_mode();
void tty_mode(int);
void ctrl_c_handler(int);

int main(){
	int response;
	tty_mode(0);
	set_cr_noecho_mode();
	set_nodelay_mode();
	signal(SIGINT,ctrl_c_handler);
	signal(SIGQUIT,SIG_IGN);
	response = get_reponse(ASK,TRIES);
	tty_mode(1);
	return response;
}

int get_reponse(char* s,int t){
	int input;
	printf("%s (y/n)?",s);
	fflush(stdout);
	while(1){
		sleep(SLEEPTIME);
		input = tolower(get_ok_char());
		printf("input :%c\n",input);
		fflush(stdout);
		if(input=='y') return 0;
		if(input=='n') return 1;
		if(t--==0) return 2;
		BEEP;
	}
}

char get_ok_char(){
	int c;
	while((c=getchar())!=EOF&&strchr("yYnN",c)==NULL);
	return c;
}

void set_cr_noecho_mode(){
	struct termios ttystate;
	tcgetattr(0,&ttystate);
	ttystate.c_lflag &= ~ICANON;
	ttystate.c_lflag &= ~ECHO;
	ttystate.c_cc[VMIN] = 1;
	tcsetattr(0,TCSANOW,&ttystate);
}

void set_nodelay_mode(){
	int termflags;
	termflags = fcntl(0,F_GETFL);
	termflags |= O_NDELAY;
	fcntl(0,F_SETFL,termflags);
}

void tty_mode(int how){
	static struct termios original_mode;
	static int original_flags;
	static int stored = 0;
	if(how==0){
		tcgetattr(0,&original_mode);
		original_flags=fcntl(0,F_GETFL);
		stored = 1;
	}else if(stored){
		tcsetattr(0,TCSANOW,&original_mode);
		fcntl(0,F_SETFL,original_flags);
	}
}

void ctrl_c_handler(int signum){
	tty_mode(1);
	exit(1);
}
