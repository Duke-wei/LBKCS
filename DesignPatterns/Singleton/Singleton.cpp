/*************************************************************************
    > File Name: Singleton.cpp
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2016年12月26日 星期一 22时13分48秒
 ************************************************************************/

#include "Singleton.h"

#include <iostream>
using namespace std;
Singleton* Singleton::_instance=0;

Singleton::Singleton(){
	cout<<"Singleton..."<<endl;
}

Singleton* Singleton::Instance(){
	if(_instance==0){
		_instance = new Singleton();
	}
	return _instance;
}
