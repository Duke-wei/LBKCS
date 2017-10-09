/*************************************************************************
    > File Name: main.cpp
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2016年12月30日 星期五 10时38分56秒
 ************************************************************************/

#include<iostream>
#include "Adapter.h"
using namespace std;
int main(){
	Adaptee *ade = new Adaptee;
	Target *adt = new Adapter(ade);
	adt->Request();
	return 0;
}
