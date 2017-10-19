/*************************************************************************
    > File Name: smsh1.c
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月14日 星期六 09时40分44秒
 ************************************************************************/

#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include "smsh.h"

#define DFL_PROMPT "> "

void fatal(char* s1,char* s2,int n){
	fprintf(stderr,"Error:%s,%s\n",s1,s2);
	exit(n);
}

void setup(){
	signal(SIGINT,SIG_IGN);
	signal(SIGQUIT,SIG_IGN);
}

int main(){
	char *cmdline,*prompt,**arglist;
	int result;
	void setup();
	prompt = DFL_PROMPT;
	setup();
	while((cmdline=next_cmd(prompt,stdin))!=NULL){
		if((arglist=splitline(cmdline))!=NULL){
			result = process(arglist);
			//result = execute(arglist);
			freelist(arglist);
		}
		free(cmdline);
	}
	return 0;
}
