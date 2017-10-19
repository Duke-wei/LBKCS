/*************************************************************************
    > File Name: varlib.c
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月14日 星期六 19时19分29秒
 ************************************************************************/
#ifndef _VARLIB_H_
#define _VARLIB_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXVARS 200

struct var{
	char *str;
	int global;
};

static struct var tab[MAXVARS];

int VLstore(char* name,char* val);

char *new_string(char* name,char* val);

char* VLlookup(char* name);

int VLexport(char* name);

static struct var* find_item(char* name,int first_blank);

void VLlist();

int VLenviron2table(char* env[]);

char** VLtable2environ();
#endif
