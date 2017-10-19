/*************************************************************************
    > File Name: fileinfo.c
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月07日 星期六 13时22分57秒
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>

void show_stat_info(char* fname,struct stat*buf){
	printf("    mode:%o\n",buf->st_mode);
	printf("    links:%lu\n",buf->st_nlink);
	printf("    user:%d\n",buf->st_uid);
	printf("    group:%d\n",buf->st_gid);
	printf("    size:%lu\n",buf->st_size);
	printf("    modtime:%lu\n",buf->st_mtime);
	printf("    name:%s\n",fname);
}

int main(int ac,char* av[]){
	struct stat info;
	if(ac>1){
		if(stat(av[1],&info)!=-1){
			show_stat_info(av[1],&info);
			return 0;
		}else{
			perror(av[1]);
		}
	}
	return 1;
}
