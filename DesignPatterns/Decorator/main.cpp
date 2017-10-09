/*************************************************************************
    > File Name: main.cpp
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2016年12月31日 星期六 11时12分31秒
 ************************************************************************/

#include<iostream>
#include "Decorator.h"
using namespace std;

int main(){
	Component* com = new ConcreteComponent();
	Decorator* dec = new ConcreteDecorator(com);
	dec->Operation();
	delete dec;
	return 0;
}

