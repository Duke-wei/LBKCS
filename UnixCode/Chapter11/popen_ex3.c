/*************************************************************************
    > File Name: popen_ex3.c
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月16日 星期一 14时13分04秒
 ************************************************************************/

#include "mylinux.h"

int main(){
	FILE *fp;
	fp = popen("mail admin backup","w");
	fprintf(fp,"Error with backup!\n");
	pclose(fp);
	return 0;
}

