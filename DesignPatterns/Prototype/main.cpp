/*************************************************************************
    > File Name: main.cpp
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2016年12月28日 星期三 13时19分53秒
 ************************************************************************/
#include "Prototype.h"
#include<iostream>
using namespace std;

int main(){
	Prototype *p = new ConcretePrototype();
	Prototype *p1 = p->Clone();
	return 0;
}

