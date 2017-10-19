/*************************************************************************
    > File Name: tinybc.c
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月16日 星期一 13时25分46秒
 ************************************************************************/
#include "mylinux.h"

void be_dc(int in[2],int out[2]){
	//管道读取端连接到stdin
	if(dup2(in[0],0)==-1) oops("dc,cannot redirect stdin",3);
	close(in[0]);
	close(in[1]);
	//管道输入端连接到stdout
	if(dup2(out[1],1)==-1) oops("dc,cannot redirect stdout",4);
	close(out[1]);
	close(out[0]);
	execlp("dc","dc","-",NULL);
	oops("Cannot run dc",5);
}

void be_bc(int todc[2],int fromdc[2]){
	int num1,num2;
	char operation[BUFSIZ],message[BUFSIZ];
	FILE *fpout,*fpin;
	close(todc[0]); //won't read from pipe to dc
	close(fromdc[1]);//won't write to pipe from dc
	fpout = fdopen(todc[1],"w");
	fpin = fdopen(fromdc[0],"r");
	if(fpout==NULL||fpin==NULL) fatal("Error convering pipes to streams");
	while(printf("tinybc:"),fgets(message,BUFSIZ,stdin)!=NULL){
		if(sscanf(message,"%d%[-+*/^%]%d",&num1,operation,&num2)!=3){
			printf("syntax error\n");
			continue;
		}
		if(fprintf(fpout,"%d\n%d\n%c\np\n",num1,num2,*operation)==EOF) fatal("Error writing");
		fflush(fpout);
		if(fgets(message,BUFSIZ,fpin)==NULL) break;
		printf("%d %c %d = %s",num1,*operation,num2,message);
	}
	fclose(fpout);
	fclose(fpin);
}

int main(){
	int pid,todc[2],fromdc[2];
	if(pipe(todc)==-1||pipe(fromdc)==-1){
		oops("pipe failed",1);
	}
	if((pid=fork())==-1){
		oops("Cannot fork",2);
	}
	if(pid==0) be_dc(todc,fromdc);
	else{
		be_bc(todc,fromdc);
		//这里的wait有什么用？
		wait(NULL);
	}
}
