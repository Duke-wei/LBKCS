/*************************************************************************
    > File Name: play_again.c
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月10日 星期二 12时44分59秒
 ************************************************************************/

#include<stdio.h>
#include<termios.h>

#define QUESTION "Do you want another transaction"

int get_reponse(char*);
void set_crmode();
void tty_mode(int);

int main(){
	int response;
	tty_mode(0);
	set_crmode();
	response = get_reponse(QUESTION);
	tty_mode(1);
	return response;
}

int get_reponse(char* s){
	int input;
	printf("%s (y/n)?",s);
	while(1){
		switch(input=getchar()){
			case 'y':
			case 'Y':return 0;
			case 'n':
			case 'N':
			case EOF:return 1;
			default:
				printf("\ncannot understand %c,",input);
				printf("Please type y or n \n");
		}
	}
}

void set_crmode(){
	struct termios ttystate;
	tcgetattr(0,&ttystate);
	ttystate.c_lflag &= ~ICANON;
	ttystate.c_cc[VMIN] = 1;
	tcsetattr(0,TCSANOW,&ttystate);
}

void tty_mode(int how){
	static struct termios original_mode;
	if(how==0)
		tcgetattr(0,&original_mode);
	else
		tcsetattr(0,TCSANOW,&original_mode);
}
