/*************************************************************************
    > File Name: main.cpp
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年01月03日 星期二 11时18分06秒
 ************************************************************************/
#include "Facade.h"
#include<iostream>
using namespace std;

int main(){
	Facade* f = new Facade();
	f->OperationWrapper();
	return 0;
}

