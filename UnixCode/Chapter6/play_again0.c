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

int main(){
	int response;
	response = get_reponse(QUESTION);
	return response;
}

int get_reponse(char* s){
	printf("%s (y/n)?",s);
	while(1){
		switch(getchar()){
			case 'y':
			case 'Y':return 0;
			case 'n':
			case 'N':
			case EOF:return 1;
		}
	}
}
