/*************************************************************************
    > File Name: ls1.c
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月07日 星期六 13时07分57秒
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>
void do_ls(char[]);

int main(int ac,char* av[]){
	if(ac==1){
		do_ls(".");
	}else{
		while(--ac){
			printf("%s:\n",*++av);
			do_ls(*av);
		}
	}
	return 0;
}

void do_ls(char dirname[]){
	DIR *dir_ptr;
	struct dirent* direntp;
	if((dir_ptr=opendir(dirname))==NULL){
		fprintf(stderr,"ls1:cannot open%s\n",dirname);
	}else{
		while((direntp=readdir(dir_ptr))!=NULL){
			printf("%s\n",direntp->d_name);
		}
		closedir(dir_ptr);
	}
}
