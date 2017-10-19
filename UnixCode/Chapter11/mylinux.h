/*************************************************************************
    > File Name: mylinux.h
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月16日 星期一 13时49分36秒
 ************************************************************************/
#ifndef _MYLINUX_H_
#define _MYLINUX_H_

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<wait.h>
#include<signal.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<fcntl.h>
#include<time.h>
#include<utmp.h>

#define oops(m,x) {perror(m);exit(x);}

void fatal(char* mess){
	fprintf(stderr,"Error: %s\n",mess);
	exit(1);
}
#endif

