/*************************************************************************
    > File Name: rotate.c
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年10月10日 星期二 11时35分22秒
 ************************************************************************/

#include<stdio.h>
#include<ctype.h>
int main(){
	int c;
	while((c=getchar())!=EOF){
		if(c=='z'){
			c='a';
		}else if(islower(c)){
			c++;
		}
		putchar(c);
	}
	return 0;
}
