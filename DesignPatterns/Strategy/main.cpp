/*************************************************************************
    > File Name: main.cpp
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年01月06日 星期五 12时15分20秒
 ************************************************************************/
#include "Context.h"
#include "strategy.h"
#include<iostream>
using namespace std;

int main(){
	Strategy* ps;
	ps=new ConcreteStrategyA();
	Context* pc = new Context(ps);
	pc->DoAction();
	if(NULL != pc)
		delete pc;
	return 0;
}

