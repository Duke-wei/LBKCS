/*************************************************************************
    > File Name: smsh.h
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月14日 星期六 10时08分46秒
 ************************************************************************/
#ifndef _SMSH_H_
#define _SMSH_H_

#include<stdio.h>
#define YES 1
#define NO 0

char* next_cmd(char*,FILE*);
char** splitline(char*);
void freelist(char**);
void* emalloc(size_t);
void* erealloc(void*,size_t);
int execute(char**);
void fatal(char*,char*,int);
int process(char**);
int is_control_command(char*);
int do_control_command(char**);
int ok_to_execute();

#endif
