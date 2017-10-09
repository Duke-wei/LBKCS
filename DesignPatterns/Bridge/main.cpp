/*************************************************************************
    > File Name: main.cpp
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2016年12月29日 星期四 11时28分43秒
 ************************************************************************/
#include "Abstraction.h"
#include "AbstractionImp.h"
#include<iostream>

using namespace std;

int main(){
	AbstractionImp *imp = new ConcreteAbstractionImpA();
	Abstraction *abs = new RefinedAbstraction(imp);
	abs->Operation();
	return 0;
}

