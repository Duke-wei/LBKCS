/*************************************************************************
    > File Name: listargs.c
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月15日 星期日 10时05分19秒
 ************************************************************************/
//试水一波:./a.out testing>xyz one two 2>oops
//结果是xyz存放stdout的输出，oops存放stderr输出，为啥？
//1.shell不把重定向标记和文件名传递给程序
//2.重定向可以出现在命令行中任意地方，并且重定向标识符周围不需要空格来区分
//试水一波:./a.out testing>xyz one two>oops
//结果是只有oops存放stdout的输出
#include<stdio.h>
int main(int ac,char* av[]){
	int i;
	printf("Number of args:%d,Args are:\n",ac);
	for(i=0;i<ac;++i){
		printf("args[%d] %s\n",i,av[i]);
	}
	fprintf(stderr,"This message is sent to stderr.\n");
	return 0;
}
