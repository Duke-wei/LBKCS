/*************************************************************************
    > File Name: main.cpp
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2016年12月26日 星期一 22时16分35秒
 ************************************************************************/

#include<iostream>
#include "Singleton.h"
using namespace std;

int main(){
	Singleton* sgn = Singleton::Instance();
	return 0;
}

