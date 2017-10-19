/*************************************************************************
    > File Name: socklib.h
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月17日 星期二 09时49分18秒
 ************************************************************************/
#ifndef _SOCKLIB_H_
#define _SOCKLIB_H_

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<wait.h>

#define oops(m) {perror(m);exit(1);}
#define HOSTLEN 256
#define BACKLOG 1

int make_server_socket_q(int,int);
int make_server_socket(int);
int connect_to_server(char *,int );
#endif
