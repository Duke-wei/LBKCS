/*************************************************************************
    > File Name: popendemo.c
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月16日 星期一 14时10分37秒
 ************************************************************************/

#include "mylinux.h"

int main(){
	FILE *fp;
	char buf[100];
	int i=0;
	fp = popen("ps|sort","r");
	while(fgets(buf,100,fp)!=NULL){
		printf("%3d %s",i++,buf);
	}
	pclose(fp);
	return 0;
}
