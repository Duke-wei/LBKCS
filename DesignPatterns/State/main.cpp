/*************************************************************************
    > File Name: main.cpp
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年01月07日 星期六 11时31分36秒
 ************************************************************************/
#include "Context.h"
#include "State.h"
#include<iostream>
using namespace std;

int main(){
	State *st = new ConcreteStateA();
	Context* con = new Context();
	con->OprationInterface();
	con->OprationInterface();
	con->OprationInterface();
	if(con!=NULL)
		delete con;
	if(st!= NULL)
		delete st;
	return 0;
}

