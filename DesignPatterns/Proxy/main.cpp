/*************************************************************************
    > File Name: main.cpp
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年01月04日 星期三 10时43分52秒
 ************************************************************************/

#include<iostream>
#include "Proxy.h"
using namespace std;

int main(){
	Subject* sub = new ConcreteSubject();
	Proxy* p = new Proxy(sub);
	p->Request();
	return 0;
}

