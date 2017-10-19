/*************************************************************************
    > File Name: process.c
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月14日 星期六 10时44分24秒
 ************************************************************************/

#include "smsh.h"


int process(char **args){
	int rv=0;
	if(args[0]==NULL) rv=0;
	else if(is_control_command(args[0])) rv=do_control_command(args);
	else if(ok_to_execute()) rv=execute(args);
	return rv;
}

